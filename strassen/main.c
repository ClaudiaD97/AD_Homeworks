#include <stdio.h>
#include "test.h"
#include "matrix.h"
#include "strassen.h"



int main(int argc, char *argv[]) {

  
  size_t n1 = 521;
  size_t n2 = 1724;
  size_t n3 = 5173;

  float **A = allocate_random_matrix(n1, n2);
  float **B = allocate_random_matrix(n2, n3);
  float **C0 = allocate_random_matrix(n1,n3);
  float **C1 = allocate_random_matrix(n1,n3);

  printf("TEST ALGORITHM ON RECTANGULAR MATRICES:\n");
  printf("Using A=%ldx%ld, B=%ldx%ld\n",n1,n2,n2,n3);
  printf("\nStrassen algorithm: %lf\n", test(rectangular_strassen, C0, A, B, n1,n2,n2,n3));
  printf("Naive algorithm: %lf\n", test(naive_matrix_multiplication, C1, A, B, n1,n2,n2,n3));
  printf("Same result: %d\n",same_matrix((float const *const *const)C0,
                               (float const *const *const)C1, n1, n3));

  deallocate_matrix(A, n1);
  deallocate_matrix(B, n2);
  deallocate_matrix(C0, n1);
  deallocate_matrix(C1, n1);

  printf("\nTEST ALGORITHM ON SQUARE MATRICES:\n");
  size_t n = 1 << 12;
  
  A = allocate_random_matrix(n, n);
  B = allocate_random_matrix(n, n);
  C0 = allocate_matrix(n, n);
  C1 = allocate_matrix(n, n);
  float **C2 = allocate_random_matrix(n,n);

  printf("\n\tStrassen's Alg opt\t Strassen's Alg\t\tNaive Alg.\tSame result\n");
  for (size_t j = 1; j <= n; j *= 2) {
    
    printf("%ld\t", j);
    fflush(stdout);
  
    printf("%lf\t\t", test(rectangular_strassen, C1, A, B, j,j,j,j));
    fflush(stdout);

    printf("%lf\t\t", test(strassen_matrix_multiplication, C2, A, B, j,j,j,j));
    fflush(stdout);

    printf("%lf\t\t", test(naive_matrix_multiplication, C0, A, B, j,j,j,j));
    fflush(stdout);
  
    printf("%d\n", same_matrix((float const *const *const)C0,
                               (float const *const *const)C1, j, j));
    
  }
  
  deallocate_matrix(A, n);
  deallocate_matrix(B, n);
  deallocate_matrix(C0, n);
  deallocate_matrix(C1, n);
  deallocate_matrix(C2, n);
  
  return 0;
}
