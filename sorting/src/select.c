#include "select.h"
#include "swap.h"
#include <stdio.h>
#include "quick_sort.h"
#include "selection_sort.h"

unsigned int select_index(void *A, const unsigned int n, 
                          const unsigned int i,
                          const size_t elem_size, 
                          total_order leq)
{   if (n<128){
        quick_sort(A,n,elem_size,leq);
        return i;
    }
    
    void *median = almost_median(A,n,elem_size,leq);
    
    void *l = A;
    void *r = A+(n-1)*elem_size;

    unsigned int *p = three_partition(A,l,r,median,elem_size,leq);
    
    size_t position1 = *p;
    size_t position2 = *(p+1);

    if (i<position1){
        return select_index(A,position1-1,i,elem_size,leq);
    } else if (i>=position1 && i<= position2){
        return i;
    } else {
        return select_index(A+position2*elem_size,n-position2,i-position2,elem_size,leq)+position2;
    }
}

void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{   
   size_t pivot = select_index(A,n,n/2,elem_size,leq);
   
   unsigned int *p = three_partition(A,A,A+elem_size*(n-1),A+pivot*elem_size,elem_size,leq);

   unsigned int new_n_1 = p[0];
   unsigned int new_n_2 = n-p[1]-1;
   if (new_n_1>1)
       quick_sort_select(A,new_n_1,elem_size,leq);
   if (new_n_2>1)
       quick_sort_select(A+(p[1]+1)*elem_size,new_n_2,elem_size,leq);
}
