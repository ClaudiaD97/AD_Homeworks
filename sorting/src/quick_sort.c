#include "quick_sort.h"
#include "swap.h"
#include "stdio.h"



void quick_sort(void *A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq)
{
    
    void *l = A;
    void *r = A+((n-1)*elem_size);
    void *p;
    unsigned int new_n_1,new_n_2;
    p = partition(A,l,r,l,elem_size,leq); //returns pointer to pivot, as pivot use l
    
    new_n_1 = (p-A)/elem_size;
    new_n_2 = n-new_n_1-1;
    if (new_n_1>1)
        quick_sort(A,new_n_1,elem_size,leq);
    if (new_n_2>1)
        quick_sort(p+elem_size,new_n_2,elem_size,leq);

}

