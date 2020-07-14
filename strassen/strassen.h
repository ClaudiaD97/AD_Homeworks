#ifndef __STRASSEN__

float **zero_padding(float const* const *const A,
                     size_t nr, size_t nc, size_t new_nr, size_t new_nc,
                     size_t start_row, size_t start_col);

void strassen_matrix_multiplication(float **C, float const *const *const A,
                                    float const *const *const B, size_t n);

void strassen_matrix_multiplication_opt(float **C, float const *const *const A,
                                    float const *const *const B, size_t n);

void strassen_aux(float **C, float const* const* const A,
                    float const* const* const B,
                    const size_t C_f_row, const size_t C_f_col,
                    const size_t A_f_row, const size_t A_f_col,
                    const size_t B_f_row, const size_t B_f_col,
                    const size_t n );

// memory optimized: use just 2 S matrices instead of 10
void strassen_aux_opt(float **C, float const* const* const A,
                    float const* const* const B,
                    const size_t C_f_row, const size_t C_f_col,
                    const size_t A_f_row, const size_t A_f_col,
                    const size_t B_f_row, const size_t B_f_col,
                    const size_t n );

void rectangular_strassen(float **C, float const *const *const A,
                                    float const *const *const B, 
                                    size_t A_rows, size_t A_cols, size_t B_rows, size_t B_cols);


#endif //__STRASSEN__
