#include <stdio.h>
#include <stdbool.h>
#include "matrix.h"

static void matrix_add_ex(matrix_t *dest, const matrix_t *a, const matrix_t *b, bool positive) {
    uint8_t row, column;
    int factor = positive ? 1 : -1;
    dest->rows = a->rows;
    dest->columns = a->columns;
    for (row = 0; row < dest->rows; row++) {
        for (column = 0; column < dest->columns; column++) {
            dest->data[row][column] = a->data[row][column] + factor * b->data[row][column];
        }
    }
}

void matrix_add(matrix_t *dest, const matrix_t *a, const matrix_t *b) {
    matrix_add_ex(dest, a, b, true);
}

void matrix_sub(matrix_t *dest, const matrix_t *a, const matrix_t *b) {
    matrix_add_ex(dest, a, b, false);
}

void matrix_mul(matrix_t *dest, const matrix_t *a, const matrix_t *b) {
    uint8_t row, column, i;
    dest->rows = a->rows;
    dest->columns = b->columns;
    for (row = 0; row < dest->rows; row++) {
        for (column = 0; column < dest->columns; column++) {
            dest->data[row][column] = 0;
            for (i = 0; i < a->columns; i++) {
                dest->data[row][column] += a->data[row][i] * b->data[i][column];
            }
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

void matrix_print(matrix_t *matrix) {
    uint8_t row, column;
    for (row = 0; row < matrix->rows; row++) {
        for (column = 0; column < matrix->columns; column++)
            printf("%5.2lf, ", matrix->data[row][column]);
        printf("\n");
    }
}
