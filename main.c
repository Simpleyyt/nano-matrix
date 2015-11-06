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
    int ret;
    uint8_t a[3][3] = {
        {1, 2, 3},
        {2, 4, 4},
        {4, 4, 5}
    };
    uint8_t b[3][3] = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
    uint8_t x[3][1] = {
        {1},
        {2},
        {3}
    };
    matrix_t a_matrix, b_matrix, dest_matrix, q_matrix, r_matrix, x_matrix;
    init_matrix(&a_matrix, 3, 3, a);
    init_matrix(&b_matrix, 3, 3, b);
    init_matrix(&x_matrix, 3, 1, x);

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

    printf("----------------------------\n");
    printf("Matrix QR decomposition test\n");
    printf("A matrix:\n");
    matrix_print(&a_matrix);
    ret = matrix_qr_decomposition(&q_matrix, &r_matrix, &a_matrix, 0);
    if (ret == MATRIX_OK) {
        printf("Q matrix:\n");
        matrix_print(&q_matrix);
        printf("R matrix:\n");
        matrix_print(&r_matrix);
        matrix_mul(&dest_matrix, &q_matrix, &r_matrix);
        printf("Q * R matrix:\n");
        matrix_print(&dest_matrix);
    } else {
        printf("QR decomposition error.\n");
    }

    printf("----------------------------\n");
    printf("Matrix solve Ax = b test\n");
    printf("A matrix:\n");
    matrix_print(&a_matrix);
    printf("x matrix:\n");
    matrix_print(&x_matrix);
    matrix_mul(&b_matrix, &a_matrix, &x_matrix);
    printf("b matrix:\n");
    matrix_print(&b_matrix);
    ret = matrix_qr_decomposition(&q_matrix, &r_matrix, &a_matrix, 2);
    if (ret == MATRIX_OK) {
        ret = matrix_solve(&dest_matrix, &q_matrix, &r_matrix, &b_matrix);
        if (ret == MATRIX_OK) {
            printf("Solved x matrix:\n");
            matrix_print(&dest_matrix);
            matrix_mul(&b_matrix, &a_matrix, &dest_matrix);
            printf("A * x matrix:\n");
            matrix_print(&b_matrix);
        } else {
            printf("Solve Ax = b error.\n");
        }
    } else {
        printf("QR decomposition error.\n");
    }

    return 0;
}
