#ifndef __UTILITIES__

#include <stdlib.h>

#include "total_order.h"

int *get_random_int_array(const unsigned int n);

int is_sorted(const void *A, const unsigned int n, 
              const size_t elem_size, 
              total_order leq);

double test(void (*sort)(void *A, const unsigned int n, 
                         const size_t elem_size, 
                         total_order leq), 
            const void *A, const unsigned int n, 
            const size_t elem_size, total_order leq, 
            const unsigned int rep, int *sorted);


void *partition(void *A, void *l, void*r, void *p, const size_t elem_size,total_order leq);

void *almost_median(void *A, const unsigned int n, const size_t elem_size, total_order leq);

void print_array(unsigned int *A,const unsigned int A_size,const size_t elem_size);


unsigned int *three_partition(void *A,void *l, void *r, void *p,const size_t elem_size,total_order leq);

#endif // __UTILITIES__