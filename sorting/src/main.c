#include <stdio.h>

#include "insertion_sort.h"
#include "quick_sort.h"
#include "select.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"
#include "utilities.h"
#include "binheap.h"

#define MAX_SIZE_ALL (1<<13)
#define MAX_SIZE_NLOGN (1<<21)
#define ARRAY_SIZE (1<<23)

#define NUM_OF_REPETITIONS 1

void test_and_print(void (*sort)(void *A, const unsigned int n, 
                         const size_t elem_size, 
                         total_order leq), 
                    const void *A, const unsigned int n, 
                    const size_t elem_size, total_order leq, 
                    const unsigned int rep)
{   
    int sorted;

    printf("\t%lf",test(sort,A,n,elem_size,leq,rep,&sorted));
    if (!sorted) {
        printf(" (KO)");
    }
    fflush(stdout);
}




int main(int argc, char *argv[])
{   
    int *A=get_random_int_array(ARRAY_SIZE);
    int *A_sorted=malloc(sizeof(int)*ARRAY_SIZE);
    int *A_rev_sorted=malloc(sizeof(int)*ARRAY_SIZE);

    for (unsigned int i=0; i<ARRAY_SIZE; i++) {
        A_sorted[i]=i;
        A_rev_sorted[i]=ARRAY_SIZE-i;
    }
    
    //const size_t A_size = 1<<10;
    /*
    const size_t A_size = ARRAY_SIZE;
    printf("A size = %ld\n",A_size);
    
    int array[] = {4,1,2,6,4,3,4,1};
    
    for (int i=0; i<A_size; ++i){
        array[i]=A_size-i;
    }
    
    
    
    A = array;

    print_array(A,A_size,sizeof(int));
    unsigned int *t = three_partition(A,A,A+(A_size-1),A+2,sizeof(int),leq_int);
    
    //select_index(A,A_size,4,sizeof(int),leq_int);
    //quick_sort_select(A,A_size,sizeof(int),leq_int);
    print_array(A,A_size,sizeof(int));
    fflush(stdout);
    */
    
    unsigned int i;
    
    printf("Size\tInsertion Sort\t          \t        \n");
    printf("    \t(Random Case)\t(Best Case)\t(Worst Case)");
    for (i=2; (1<<i)<=MAX_SIZE_ALL; i++) {
        const unsigned int A_size=1<<i;
        printf("\n2^%d",i);
        test_and_print(insertion_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(insertion_sort, A_sorted,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(insertion_sort, A_rev_sorted,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
    }
    printf("\n\n\n");
     //this works
     
    printf("Size\tQuick Sort\t           \tQuick Sort + Select\n");
    printf("    \t(Random Case)\t(Worst Case)\t(Random Case)\t(Worst Case)");
    fflush(stdout);
    for (i=2; (1<<i)<=MAX_SIZE_ALL; i++) {
        const unsigned int A_size=1<<i;
        printf("\n2^%d",i);
        test_and_print(quick_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort, A_sorted,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        
        test_and_print(quick_sort_select, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort_select, A_sorted,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
                
    }
    printf("\n\n\n");
    
    printf("Size\tInsertion Sort\tQuick Sort\tBubble Sort\tSelection Sort\tHeap Sort\n");
    printf("    \t(Random Case)\t(Random Case)\t\t\t");
    for (i=2; (1<<i)<=MAX_SIZE_ALL; i++) {
        const unsigned int A_size=1<<i;
        printf("\n2^%d",i);
        test_and_print(insertion_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(bubble_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(selection_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(heap_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
    }
    printf("\n\n\n");
    printf("Size\tQuick Sort\tQuick Sort +\tHeap Sort\n");
    printf("    \t          \t  Select\n");
    printf("    \t(Random Case)\t(Random Case)\t");
    for (; (1<<i)<=MAX_SIZE_NLOGN; i++) {
        const unsigned int A_size=1<<i;
        printf("\n2^%d",i);
        test_and_print(quick_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(quick_sort_select, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
        test_and_print(heap_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
    }

    printf("\n");
    
    

    
    free(A);
    
    free(A_sorted);
    free(A_rev_sorted);
    return 0;
}