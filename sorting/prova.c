#include <stdio.h>

#include "insertion_sort.h"
#include "quick_sort.h"
#include "select.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "heap_sort.h"
#include "utilities.h"

#define MAX_SIZE_ALL (1<<13)
#define MAX_SIZE_NLOGN (1<<20)
#define ARRAY_SIZE (1<<23)

#define NUM_OF_REPETITIONS 15

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

    test_and_print(quick_sort, A,
                       A_size, sizeof(int),
                       leq_int, NUM_OF_REPETITIONS);
}