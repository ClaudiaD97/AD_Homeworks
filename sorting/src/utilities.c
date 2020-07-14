#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#include "swap.h"
#include "total_order.h"
#include "quick_sort.h"
#include "selection_sort.h"

int *get_random_int_array(const unsigned int n) 
{
  
  int *A=(int *)malloc(sizeof(int)*n);
  
  srand(10);
  for (unsigned int i = 0; i < n; i++) {
    A[i] = (rand() - RAND_MAX / 2) % n*n;
  }

  return A;
}

int is_sorted(const void *A, const unsigned int n, 
              const size_t elem_size, 
              total_order leq)
{
  for (const void *addr=A; addr!=A+(n-1)*elem_size; 
    addr+=elem_size) {
        
    if (!leq(addr, addr+elem_size)) {
      return 0;
    }
  }

  return 1;
}

double test(void (*sort)(void *A, const unsigned int n, 
                         const size_t elem_size, 
                         total_order leq), 
            const void *A, const unsigned int n, 
            const size_t elem_size, total_order leq, 
            const unsigned int rep,
            int *sorted)
{ 
 
  struct timespec requestStart, requestEnd;
  double accum, cpy_accum;
  const size_t total_size = n*elem_size;

  void *B=malloc(total_size);

  // Collecting time for copy A into B and sorting B
  clock_gettime(CLOCK_REALTIME, &requestStart);
  
  for (size_t i = 0; i < rep; i++) {
    memcpy(B,A+i*n,total_size);
    
    sort(B,n,elem_size,leq);
  }
  clock_gettime(CLOCK_REALTIME, &requestEnd);
  
  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;


  if (sorted != NULL) {
    *sorted = is_sorted(B, n, elem_size, leq);
  }

  // Collecting time for copying A in B
  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t i = 0; i < rep; i++) {
    memcpy(B,A+i*n,total_size);
  }
  clock_gettime(CLOCK_REALTIME, &requestEnd);

  cpy_accum = (requestEnd.tv_sec - requestStart.tv_sec) +
             (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;

  free(B);

  double secs = (accum-cpy_accum) / rep;

  return (secs<0?0:secs);
}

void *partition(void *A,void *l, void *r, void *p,const size_t elem_size,total_order leq){
    //printf("hello from partition\n");
    swap(l,p,elem_size);
    void *i = l+elem_size;
    void *j = r;
    while (i<=j){
       if (leq(l,j)){
           j -= elem_size;
       } else{
           swap(i,j,elem_size);
           i += elem_size;
       }
    }
    //printf("end while\n");
    swap(l,j,elem_size); //now pivot is in position j
    return j;  
}


// this function modifies the array
void *almost_median(void *A, const unsigned int n, const size_t elem_size, total_order leq){
    //base case sort and take element in position n/2
  
  if (n<=128){
    //printf("base_case\n");
    quick_sort(A,n,elem_size,leq);
    return A+(n/2-1)*elem_size;
  }
  size_t reminder = n%5;
  size_t last_median_position;
  if (reminder>=3 | reminder ==0){
    last_median_position = (n-reminder)+3;
  } else {
    last_median_position = n;
  }

  // call a sort on each chunk of size 5
  for (int i=0; i<n-reminder; i+=5){
    selection_sort(A+(i*elem_size),5,elem_size,leq);
  }
  selection_sort(A+((n-reminder)*elem_size),reminder,elem_size,leq);
//correct
/*  printf("A after partial sorting:\n");
  for (size_t i=0; i<n; ++i){
    printf("%d,",((int *)A)[i]);
  }
  printf("\n"); */

  // put medians of chunks in a new array, then multiply index by 5+2

  size_t new_n = n/5 + (reminder!=0);
  //printf("new size = %d reminder = %d\n",new_n,reminder); // correct

  void *B=(void *)malloc(elem_size*new_n);

  for (size_t i = 0; i < new_n-1; i++) {
    memcpy(B+i*elem_size,A+(i*5+2)*elem_size,elem_size);
    //printf("copying %ld\n",((int*)A)[5*i+2]);
  }
  if (reminder>=3 | reminder==0){
      memcpy(B+(new_n-1)*elem_size,A+(new_n-1+2)*elem_size,elem_size);
      //printf("copying %ld\n",((int*)A)[new_n-1+2]);
  } else {
      //printf("index in b = %ld, index in A = %ld\n",new_n-1,n-1);
      memcpy(B+(new_n-1)*elem_size,A+(n-1)*elem_size,elem_size);
      //printf("copying %ld\n",((int*)A)[n-1]);
  }
/*
  for (size_t i=0; i<new_n; ++i){
    printf("%d,",((int *)B)[i]);
  }
  printf("\n ok\n");
*/
  // now recursivly compute it
  void *p= almost_median(B,new_n,elem_size,leq);
  //printf("hello\n");
  //transform index in terms of A
  // if the index returned is not the last one !new_n-1
  size_t returned_index = (p-B)/elem_size;
  free(B);
  //printf("returned index = %ld\n",returned_index);
  if (returned_index==new_n-1){
    return A+(last_median_position*elem_size);
  } else {
    return A+(returned_index*5+2)*elem_size;
  }
  
}

void print_array(unsigned int *A,const unsigned int A_size,const size_t elem_size){
    for (int i=0; i<A_size; ++i){
        printf("%d,",*(A+i));
    }
    printf("\n");
    fflush(stdout);
}

// returns an array of 2 pointers, i and j.
// if they coincide it's like partition and it means that there is just one value
// else all elements between them have the same value of the pivot
unsigned int *three_partition(void *A,void *l, void *r, void *p,const size_t elem_size,total_order leq){
  
  swap(r,p,elem_size);
  void *i = l;
  void *j = r-elem_size;
  void *copies = r-elem_size;
  while (i<=j){
    if (leq(r,j) && leq(j,r)){
      swap(copies,j,elem_size);
      copies -= elem_size;
      j -= elem_size;
    } else if (leq(r,j)){
      j -= elem_size;
    } else {
      swap(i,j,elem_size);
      i += elem_size;
    }
  }
  
  unsigned int rep = (r-copies)/elem_size;

  for (size_t a=1; a<=rep; ++a){
      swap(copies+a*elem_size, j+a*elem_size,elem_size);
  } 
  
  unsigned int res = (j+elem_size-l)/elem_size;
  unsigned int *result = (unsigned int *)malloc(sizeof(unsigned int)*2);
  result[0] = res; // index of first element = pivot
  result[1] = res+rep-1; // index of last element = pivot
  
  return result;
  
} 
