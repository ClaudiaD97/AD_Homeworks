#include "bubble_sort.h"
#include "swap.h"
#include <stdio.h>

void bubble_sort(void *A, const unsigned int n, 
                 const size_t elem_size, 
                 total_order leq)
{   
    for (int i=n-1; i>0; --i){
        //printf("i=%d\n",i);
        for (int j=0; j<i; ++j){
            //printf("j=%d",j);
            //printf("%d, ",!leq(A+(j*elem_size),A+((j+1)*elem_size)));
            if (!leq(A+(j*elem_size),A+((j+1)*elem_size))){
                swap(A+(j*elem_size),A+((j+1)*elem_size),elem_size);
            }
        }
    }
}