#include "heap_sort.h"
#include "binheap.h"
#include <stdio.h>
#include "swap.h"

void reverse_array(void *A, const size_t n, const size_t elem_size){
    for (size_t i=0; i<n/2; ++i){
        swap(A+i*elem_size,A+(n-1-i)*elem_size,elem_size);
    }
}

void heap_sort(void *A, const unsigned int n, 
               const size_t elem_size, 
               total_order leq)
{   
    binheap_type *H = build_heap(A,n,n,elem_size,leq);
    
    for (size_t i=n; i>1; --i){
        extract_min(H);
    }
    
    delete_heap(H);
    //but A is ordered in the inverse order
    reverse_array(A,n,elem_size);
}
