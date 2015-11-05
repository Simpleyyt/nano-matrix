#include <stdio.h>
#include "matrix.h"

void init_matrix(matrix_t *matrix, uint8_t row, uint8_t column, uint8_t data[row][column]) {
    matrix->rows = row;
    matrix->columns = column;
    for (row = 0; row < matrix->rows; row++) {
        for (column = 0; column < matrix->columns; column++) {
           matrix->data[row][column] = data[row][column];
        }
    }
}

int main() {
    uint8_t a[3][3] = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5}
    };
    uint8_t b[3][3] = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
    matrix_t a_matrix, b_matrix, dest_matrix;
    init_matrix(&a_matrix, 3, 3, a);
    init_matrix(&b_matrix, 3, 3, b);

    printf("----------------------------\n");
    printf("Matrix add test\n");
    printf("A matrix:\n");
    matrix_print(&a_matrix);
    printf("B matrix:\n");
    matrix_print(&b_matrix);
    printf("A + B matrix:\n");
    matrix_add(&dest_matrix, &a_matrix, &b_matrix);
    matrix_print(&dest_matrix);

    printf("----------------------------\n");
    printf("Matrix sub test\n");
    printf("A matrix:\n");
    matrix_print(&a_matrix);
    printf("B matrix:\n");
    matrix_print(&b_matrix);
    printf("A - B matrix:\n");
    matrix_sub(&dest_matrix, &a_matrix, &b_matrix);
    matrix_print(&dest_matrix);

    printf("----------------------------\n");
    printf("Matrix mul test\n");
    printf("A matrix:\n");
    matrix_print(&a_matrix);
    printf("B matrix:\n");
    matrix_print(&b_matrix);
    printf("A * B matrix:\n");
    matrix_mul(&dest_matrix, &a_matrix, &b_matrix);
    matrix_print(&dest_matrix);

    printf("----------------------------\n");
    printf("Matrix tranpose test\n");
    printf("B matrix:\n");
    matrix_print(&b_matrix);
    printf("B tranpose matrix:\n");
    matrix_tranpose(&dest_matrix, &b_matrix);
    matrix_print(&dest_matrix);

    return 0;
}
