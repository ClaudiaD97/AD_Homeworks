#include "selection_sort.h"
#include "swap.h"

void selection_sort(void *A, const unsigned int n, 
                    const size_t elem_size, 
                    total_order leq)
{   
    size_t max_index;
    for (size_t i=n; i>0; --i){
        max_index=0; 
        for (size_t j=1; j<i; ++j){
            if (!leq(A+j*elem_size,A+max_index*elem_size)){
                max_index = j;
            }
        }
        swap(A+max_index*elem_size,A+(i-1)*elem_size,elem_size);
    }
}