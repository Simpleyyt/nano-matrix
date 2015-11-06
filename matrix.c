#include <stdio.h>
#include "matrix.h"

static void matrix_addsub(matrix_t *dest, const matrix_t *a, const matrix_t *b, uint8_t add) {
    uint8_t row, column;
    dest->rows = a->rows;
    dest->columns = a->columns;
    for (row = 0; row < dest->rows; row++) {
        for (column = 0; column < dest->columns; column++) {
            if (add)
                dest->data[row][column] = a->data[row][column] + b->data[row][column];
            else
                dest->data[row][column] = a->data[row][column] - b->data[row][column];

        }
    }
}

static void subtract_projection(MATRIX_TYPE *v, const MATRIX_TYPE *u, MATRIX_TYPE dot, int n) {
    while (n--) {
        MATRIX_TYPE product = dot * (*u);
        *v -= product;
        v += MATRIX_SIZE;
        u += MATRIX_SIZE;
    }
}

void matrix_add(matrix_t *dest, const matrix_t *a, const matrix_t *b) {
    matrix_addsub(dest, a, b, 1);
}

void matrix_sub(matrix_t *dest, const matrix_t *a, const matrix_t *b) {
    matrix_addsub(dest, a, b, 0);
}

void matrix_mul(matrix_t *dest, const matrix_t *a, const matrix_t *b) {
    uint8_t row, column, i;
    dest->rows = a->rows;
    dest->columns = b->columns;
    for (row = 0; row < dest->rows; row++) {
        for (column = 0; column < dest->columns; column++) {
            dest->data[row][column] = array_dot(
                &a->data[row][0], 1,
                &b->data[0][column], MATRIX_SIZE,
                a->columns
            );
        }
    }
}

void matrix_tranpose(matrix_t *dest, const matrix_t *matrix) {
    uint8_t row, column;
    dest->rows = matrix->columns;
    dest->columns = matrix->rows;
    for (row = 0; row < dest->rows; row++) {
        for (column = 0; column < dest->columns; column++) {
            dest->data[row][column] = matrix->data[column][row];
        }
    }
}


void matrix_qr_decomposition(matrix_t *q, matrix_t *r, const matrix_t *matrix, int reorthogonalize) {
    int i, j, reorth;
    MATRIX_TYPE dot, norm;
    uint8_t stride = MATRIX_SIZE;
    uint8_t n = matrix->rows;

    if (q != matrix) {
        *q = *matrix;
    }

    r->columns = matrix->columns;
    r->rows = matrix->columns;
    matrix_fill(r, 0);

    for (j = 0; j < q->columns; j++) {
        for (reorth = 0; reorth <= reorthogonalize; reorth++) {
            for (i = 0; i < j; i++) {
                MATRIX_TYPE *v = &q->data[0][j];
                MATRIX_TYPE *u = &q->data[0][i];

                dot = array_dot(v, stride, u, stride, n);
                subtract_projection(v, u, dot, n);
                r->data[i][j] += dot;
            }
        }

        norm = array_norm(&q->data[0][j], stride, n);
        r->data[i][j] = norm;

        for (i = 0; i < n; i++) {
            q->data[i][j] = q->data[i][j] / norm;
        }
    }
}

void matrix_fill(matrix_t *dest, MATRIX_TYPE value) {
    int row, column;
    for (row = 0; row < dest->rows; row++) {
        for (column = 0; column < dest->columns; column++) {
            dest->data[row][column] = value;
        }
    }
}
void matrix_print(matrix_t *matrix) {
    uint8_t row, column;
    for (row = 0; row < matrix->rows; row++) {
        for (column = 0; column < matrix->columns; column++)
            printf("%5.2lf, ", matrix->data[row][column]);
        printf("\n");
    }
}
