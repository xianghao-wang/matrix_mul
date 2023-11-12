#ifndef MATRIX_MUL_KERNEL_H
#define MATRIX_MUL_KERNEL_H

typedef struct {
    double **mat;
    int rows;
    int cols;
} matrix;

void mul(matrix A, matrix B, matrix C);

#endif
