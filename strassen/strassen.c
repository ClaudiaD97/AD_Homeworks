#include "matrix.h"
#include <stdio.h>

void sub_matrix_blocks(float **C, float const* const* const A,
               float const* const* const B,
               const size_t C_f_row, const size_t C_f_col,
               const size_t A_f_row, const size_t A_f_col,
               const size_t B_f_row, const size_t B_f_col,
               const size_t n)
{
    for (size_t y=0; y<n; y++){
        for (size_t x=0; x<n; x++){
            C[y+C_f_row][x+C_f_col]=A[y+A_f_row][x+A_f_col]-B[y+B_f_row][x+B_f_col];
        }
    }
}

void add_matrix_blocks(float **C, float const* const* const A,
               float const* const* const B,
               const size_t C_f_row, const size_t C_f_col,
               const size_t A_f_row, const size_t A_f_col,
               const size_t B_f_row, const size_t B_f_col,
               const size_t n)
{
    for (size_t y=0; y<n; y++){
        for (size_t x=0; x<n; x++){
            C[y+C_f_row][x+C_f_col]=A[y+A_f_row][x+A_f_col]+B[y+B_f_row][x+B_f_col];
        }
    }
}

void naive_aux(float **C, float const *const *const A,
               float const *const * const B,
               const size_t C_f_row, const size_t C_f_col,
               const size_t A_f_row, const size_t A_f_col,
               const size_t B_f_row, const size_t B_f_col,
               const size_t n)
{  
  for (size_t y = 0; y < n; y++) {
    for (size_t x = 0; x < n; x++) {
      float value = 0.0;
      for (size_t z = 0; z < n; z++) {
        value += A[y + A_f_row][z + A_f_col]*B[z + B_f_row][x + B_f_col];
      }
      C[y + C_f_row][x + C_f_col] = value;
    }
  }
}

// This function fills a matrix of dimansion nr x nc with 0 to reach size new_nr x new_nc
float **zero_padding(float const *const *const A,
                     size_t nr, size_t nc, size_t new_nr, size_t new_nc,
                     size_t start_row, size_t start_col){
    // allocate a matrix of new size
    float **M = allocate_matrix(new_nr,new_nc);
    
    //fill it
    for (size_t i=0; i<nr; ++i){
        for (size_t j=0; j<nc; ++j){
            M[i][j]=A[start_row+i][start_col+j];
        }
        
        for (size_t j=nc; j<new_nc; ++j){
            M[i][j]=0;
        }
    }
    
    for (size_t i=nr; i<new_nr; ++i){
        for (size_t j=0; j<new_nc; ++j){
            M[i][j]=0;
        }
    }
    
    return M;
}

void strassen_aux(float **C, float const* const* const A,
                    float const* const* const B,
                    const size_t C_f_row, const size_t C_f_col,
                    const size_t A_f_row, const size_t A_f_col,
                    const size_t B_f_row, const size_t B_f_col,
                    const size_t n )
{   
    
    // if n small call naive 
    if (n<=64){
        naive_aux(C,A,B,C_f_row,C_f_col,
                    A_f_row, A_f_col,
                    B_f_row, B_f_col,n);
        return;
    }

     if(n%2 == 1)
    {
      float **A1 = zero_padding(A,n,n,n+1,n+1,A_f_row,A_f_col);
      float **B1 = zero_padding(B,n,n,n+1,n+1,B_f_row,B_f_col);
      float **C1 = allocate_matrix(n+1,n+1);
      strassen_aux(C1, (const float * const* const) A1, (const float * const* const) B1, 0, 0, 0, 0, 0, 0, n+1);

      for (size_t i=C_f_row; i<C_f_row+n; ++i){
        for (size_t j=C_f_col; j<C_f_col+n; ++j){
          C[i][j] = C1[i][j];
        }
      }

      deallocate_matrix(A1, n);
      deallocate_matrix(B1, n);
      deallocate_matrix(C1, n);

      return;
    }

    //size of blocks
    size_t n2 = n/2;
    //arrays of matrices S and P
    float ***S = (float ***)malloc(sizeof(float **)*10);
    for (size_t i=0; i<10; i++ ){
         S[i] = allocate_matrix(n2,n2);
    }

    float ***P = (float ***)malloc(sizeof(float **)*7);
    for (size_t i=0; i<7; i++ ){
         P[i] = allocate_matrix(n2,n2);
    }
        
    //S1=B12-B22 
    sub_matrix_blocks(S[0],B,B,0,0,B_f_row,B_f_col+n2,B_f_row+n2,B_f_col+n2,n2);
    //P1=A11*S1
    strassen_aux(P[0],A,(const float* const* const)S[0],0,0,A_f_row,A_f_col,0,0,n2);
    //S2=A11+A12 
    add_matrix_blocks(S[1],A,A,0,0,A_f_row,A_f_col,A_f_row,A_f_row+n2,n2);
    //P2=S2*B22 
    strassen_aux(P[1],(const float* const* const)S[1],B,0,0,0,0,B_f_row+n2,B_f_col+n2,n2);
    //S3=A21+A22 
    add_matrix_blocks(S[2],A,A,0,0,A_f_row+n2,A_f_col,A_f_row+n2,A_f_col+n2,n2);
    //P3=S3*B11
    strassen_aux(P[2],(const float* const* const)S[2],B,0,0,0,0,B_f_row,B_f_col,n2);
    //S4=B21-B11 
    sub_matrix_blocks(S[3],B,B,0,0,B_f_row+n2,B_f_col,B_f_row,B_f_col,n2);
    //P4=A22*S4
    strassen_aux(P[3],A,(const float* const* const)S[3],0,0,A_f_row+n2,A_f_col+n2,0,0,n2);
    //S5=A11+A22 
    add_matrix_blocks(S[4],A,A,0,0,A_f_row,A_f_col,A_f_row+n2,A_f_col+n2,n2);
    //S6=B11+B22 
    add_matrix_blocks(S[5],B,B,0,0,B_f_row,B_f_col,B_f_row+n2,B_f_col+n2,n2);
    //P5=S5*S6
    strassen_aux(P[4],(const float* const* const)S[4],(const float* const* const)S[5],0,0,0,0,0,0,n2);
    //S7=A12-A22 
    sub_matrix_blocks(S[6],A,A,0,0,A_f_row,A_f_col+n2,A_f_row+n2,A_f_col+n2,n2);
    //S8=B21+B22 
    add_matrix_blocks(S[7],B,B,0,0,B_f_row+n2,B_f_col,B_f_row+n2,B_f_col+n2,n2);
    //P6=S7*S8
    strassen_aux(P[5],(const float* const* const)S[6],(const float* const* const)S[7],0,0,0,0,0,0,n2);
    //S9=A11-A21 
    sub_matrix_blocks(S[8],A,A,0,0,A_f_row,A_f_col,A_f_row+n2,A_f_col,n2);
    //S10=B11+B12 
    add_matrix_blocks(S[9],B,B,0,0,B_f_row,B_f_col,B_f_row,B_f_col+n2,n2);
    //P7=S9*S10
    strassen_aux(P[6],(const float* const* const)S[8],(const float* const* const)S[9],0,0,0,0,0,0,n2);
    
    //C11=P5+P4-P2+P6
    add_matrix_blocks(C,(const float* const* const)P[4],(const float* const* const)P[3],C_f_row,C_f_col,0,0,0,0,n2);
    sub_matrix_blocks(C,C,(const float* const* const)P[1],C_f_row,C_f_col,C_f_row,C_f_col,0,0,n2);
    add_matrix_blocks(C,C,(const float* const* const)P[5],C_f_row,C_f_col,C_f_row,C_f_col,0,0,n2);
    //C12=P1+P2
    add_matrix_blocks(C,(const float* const* const)P[0],(const float* const* const)P[1],C_f_row,C_f_col+n2,0,0,0,0,n2);
    //C21=P3+P4
    add_matrix_blocks(C,(const float* const* const)P[2],(const float* const* const)P[3],C_f_row+n2,C_f_col,0,0,0,0,n2);
    //C22=P5+P1-P3-P7
    add_matrix_blocks(C,(const float* const* const)P[4],(const float* const* const)P[0],C_f_row+n2,C_f_col+n2,0,0,0,0,n2);
    sub_matrix_blocks(C,C,(const float* const* const)P[2],C_f_row+n2,C_f_col+n2,C_f_row+n2,C_f_col+n2,0,0,n2);
    sub_matrix_blocks(C,C,(const float* const* const)P[6],C_f_row+n2,C_f_col+n2,C_f_row+n2,C_f_col+n2,0,0,n2);

    //deallocate S and P
    for (size_t i=0; i<10; i++ ){
        deallocate_matrix(S[i],n2);
    }
    free(S);

    for (size_t i=0; i<7; i++ ){
        deallocate_matrix(P[i],n2);
    }
    free(P);
}


void strassen_aux_opt(float **C, float const* const* const A,
                    float const* const* const B,
                    const size_t C_f_row, const size_t C_f_col,
                    const size_t A_f_row, const size_t A_f_col,
                    const size_t B_f_row, const size_t B_f_col,
                    const size_t n )
{   
    
    // if n small call naive 
    if (n<=64){
        naive_aux(C,A,B,C_f_row,C_f_col,
                    A_f_row, A_f_col,
                    B_f_row, B_f_col,n);
        return;
    }

     if(n%2 == 1)
    {
      float **A1 = zero_padding(A,n,n,n+1,n+1,A_f_row,A_f_col);
      float **B1 = zero_padding(B,n,n,n+1,n+1,B_f_row,B_f_col);
      float **C1 = allocate_matrix(n+1,n+1);
      strassen_aux_opt(C1, (const float * const* const) A1, (const float * const* const) B1, 0, 0, 0, 0, 0, 0, n+1);

      for (size_t i=C_f_row; i<C_f_row+n; ++i){
        for (size_t j=C_f_col; j<C_f_col+n; ++j){
          C[i][j] = C1[i][j];
        }
      }

      deallocate_matrix(A1, n);
      deallocate_matrix(B1, n);
      deallocate_matrix(C1, n);

      return;
    }

    //size of blocks
    size_t n2 = n/2;
    //array of matrices S: 2 is enough
    float ***S = (float ***)malloc(sizeof(float **)*2);
    for (size_t i=0; i<2; i++ ){
         S[i] = allocate_matrix(n2,n2);
    }

    float ***P = (float ***)malloc(sizeof(float **)*7);
    for (size_t i=0; i<7; i++ ){
         P[i] = allocate_matrix(n2,n2);
    }
        
    //S1=B12-B22 (S1)
    sub_matrix_blocks(S[0],B,B,0,0,B_f_row,B_f_col+n2,B_f_row+n2,B_f_col+n2,n2);
    //P1=A11*S1
    strassen_aux_opt(P[0],A,(const float* const* const)S[0],0,0,A_f_row,A_f_col,0,0,n2);
    //S2=A11+A12 - (S1)
    add_matrix_blocks(S[0],A,A,0,0,A_f_row,A_f_col,A_f_row,A_f_row+n2,n2);
    //P2=S2*B22 
    strassen_aux_opt(P[1],(const float* const* const)S[0],B,0,0,0,0,B_f_row+n2,B_f_col+n2,n2);
    //S3=A21+A22 (S1)
    add_matrix_blocks(S[0],A,A,0,0,A_f_row+n2,A_f_col,A_f_row+n2,A_f_col+n2,n2);
    //P3=S3*B11
    strassen_aux_opt(P[2],(const float* const* const)S[0],B,0,0,0,0,B_f_row,B_f_col,n2);
    //S4=B21-B11 (S1)
    sub_matrix_blocks(S[0],B,B,0,0,B_f_row+n2,B_f_col,B_f_row,B_f_col,n2);
    //P4=A22*S4
    strassen_aux_opt(P[3],A,(const float* const* const)S[0],0,0,A_f_row+n2,A_f_col+n2,0,0,n2);
    //S5=A11+A22 (S1)
    add_matrix_blocks(S[0],A,A,0,0,A_f_row,A_f_col,A_f_row+n2,A_f_col+n2,n2);
    //S6=B11+B22 (S2)
    add_matrix_blocks(S[1],B,B,0,0,B_f_row,B_f_col,B_f_row+n2,B_f_col+n2,n2);
    //P5=S5*S6
    strassen_aux_opt(P[4],(const float* const* const)S[0],(const float* const* const)S[1],0,0,0,0,0,0,n2);
    //S7=A12-A22 (S1)
    sub_matrix_blocks(S[0],A,A,0,0,A_f_row,A_f_col+n2,A_f_row+n2,A_f_col+n2,n2);
    //S8=B21+B22 (S2)
    add_matrix_blocks(S[1],B,B,0,0,B_f_row+n2,B_f_col,B_f_row+n2,B_f_col+n2,n2);
    //P6=S7*S8
    strassen_aux_opt(P[5],(const float* const* const)S[0],(const float* const* const)S[1],0,0,0,0,0,0,n2);
    //S9=A11-A21 (S1)
    sub_matrix_blocks(S[0],A,A,0,0,A_f_row,A_f_col,A_f_row+n2,A_f_col,n2);
    //S10=B11+B12 (S2)
    add_matrix_blocks(S[1],B,B,0,0,B_f_row,B_f_col,B_f_row,B_f_col+n2,n2);
    //P7=S9*S10
    strassen_aux_opt(P[6],(const float* const* const)S[0],(const float* const* const)S[1],0,0,0,0,0,0,n2);
    
    //C11=P5+P4-P2+P6
    add_matrix_blocks(C,(const float* const* const)P[4],(const float* const* const)P[3],C_f_row,C_f_col,0,0,0,0,n2);
    sub_matrix_blocks(C,C,(const float* const* const)P[1],C_f_row,C_f_col,C_f_row,C_f_col,0,0,n2);
    add_matrix_blocks(C,C,(const float* const* const)P[5],C_f_row,C_f_col,C_f_row,C_f_col,0,0,n2);
    //C12=P1+P2
    add_matrix_blocks(C,(const float* const* const)P[0],(const float* const* const)P[1],C_f_row,C_f_col+n2,0,0,0,0,n2);
    //C21=P3+P4
    add_matrix_blocks(C,(const float* const* const)P[2],(const float* const* const)P[3],C_f_row+n2,C_f_col,0,0,0,0,n2);
    //C22=P5+P1-P3-P7
    add_matrix_blocks(C,(const float* const* const)P[4],(const float* const* const)P[0],C_f_row+n2,C_f_col+n2,0,0,0,0,n2);
    sub_matrix_blocks(C,C,(const float* const* const)P[2],C_f_row+n2,C_f_col+n2,C_f_row+n2,C_f_col+n2,0,0,n2);
    sub_matrix_blocks(C,C,(const float* const* const)P[6],C_f_row+n2,C_f_col+n2,C_f_row+n2,C_f_col+n2,0,0,n2);

    //deallocate S and P
    for (size_t i=0; i<2; i++ ){
        deallocate_matrix(S[i],n2);
    }
    free(S);

    for (size_t i=0; i<7; i++ ){
        deallocate_matrix(P[i],n2);
    }
    free(P);
}


// this function works on any square matrix
void strassen_matrix_multiplication(float **C, float const *const *const A,
                                    float const *const *const B, size_t n) 
{   
   strassen_aux(C,A,B,0,0,0,0,0,0,n);
}


// using optimized version of strassen_aux
void strassen_matrix_multiplication_opt(float **C, float const *const *const A,
                                    float const *const *const B, size_t n) 
{   
   strassen_aux_opt(C,A,B,0,0,0,0,0,0,n);
}

size_t find_min(size_t a, size_t b, size_t c){
    size_t tmp;
    if (a<=b){tmp=a;} else {tmp=b;}
    if (c<tmp){tmp=c;}
    return tmp;
}

size_t find_max(size_t a, size_t b, size_t c){
    size_t tmp;
    if (a>=b){tmp=a;} else {tmp=b;}
    if (c>tmp){tmp=c;}
    return tmp;
}

// now I want a function working also on rectangular matrix
// I suppose C  has the right size otherwise error
void rectangular_strassen(float **C, float const *const *const A,
                                    float const *const *const B, 
                                    size_t A_rows, size_t A_cols, size_t B_rows, size_t B_cols)
{   
    if (A_cols != B_rows){
        printf("I cannot multiply these matrices\n");
        return;
    }
    //if both square matrices use the basic function
    if (A_rows==A_cols & A_rows==B_cols){
        strassen_matrix_multiplication_opt(C,A,B,A_rows); 
        return;
    }
    //choose the minimum size and max 
    size_t chunk_size = find_min(A_rows,A_cols,B_cols);
    size_t max = find_max(A_rows,A_cols,B_cols);
    
    // if max smaller than 128 I use naive algorithm
    if (max < 64){
        naive_matrix_multiplication(C,A,B,A_rows,A_cols,B_rows,B_cols);
        return;
    }
    
    // zero padding A and B so they are divisible in minxmin blocks
    unsigned int A_row_chunks = A_rows/chunk_size + !(A_rows%chunk_size==0);
    unsigned int A_col_chunks = A_cols/chunk_size + !(A_cols%chunk_size==0);
    unsigned int B_row_chunks = B_rows/chunk_size + !(B_rows%chunk_size==0);
    unsigned int B_col_chunks = B_cols/chunk_size + !(B_cols%chunk_size==0);

    size_t A_rows_new = A_row_chunks*chunk_size;
    size_t A_cols_new = A_col_chunks*chunk_size;
    size_t B_rows_new = B_row_chunks*chunk_size;
    size_t B_cols_new = B_col_chunks*chunk_size;

    float **A1 = zero_padding(A,A_rows,A_cols,A_rows_new,A_cols_new,0,0);
    float **B1 = zero_padding(B,B_rows,B_cols,B_rows_new,B_cols_new,0,0);
    
    // result in a matrix C1 of dimension A_rows_new*B_cols_new values 0
    float **C1 = allocate_matrix(A_rows_new,B_cols_new);
    for (size_t i=0; i<A_rows_new; ++i){
        for (size_t j=0; j<B_cols_new; ++j){
            C1[i][j]=0;
        }
    }

        
    // needed to sum up blocks
    float **aux = allocate_matrix(chunk_size,chunk_size);

    for (unsigned int i=0; i<A_rows_new; i+=chunk_size){
        for (unsigned int j=0; j<B_cols_new; j+=chunk_size){
            
            for (size_t t=0; t<A_cols_new; t+=chunk_size){
                //call strassen_aux on each chunk 
                strassen_aux_opt(aux,A1,B1,0,0,i,t,t,j,chunk_size);
                //sum up in C1 using add_matrix 
                add_matrix_blocks(C1,C1,aux,i,j,i,j,0,0,chunk_size);
            }
            
        }
    }
    
    //fill C
    for (size_t i=0; i<A_rows; i++){
        for (size_t j=0; j<B_cols; j++){
            C[i][j]=C1[i][j];
        }
    }

    deallocate_matrix(aux,chunk_size);
    deallocate_matrix(C1,A_rows_new);
    deallocate_matrix(A1,A_rows_new);
    deallocate_matrix(B1,B_rows_new);
}
