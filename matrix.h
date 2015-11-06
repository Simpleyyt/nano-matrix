#ifndef MATRIX_H
#define MATRIX_H

#ifndef MATRIX_TYPE
#define MATRIX_TYPE     double
#define MATRIX_EPLILON  0.00000001
#endif

#ifndef MATRIX_SIZE
#define MATRIX_SIZE 4
#endif

#include <stdint.h>
#include "array.h"

typedef struct {
    MATRIX_TYPE data[MATRIX_SIZE][MATRIX_SIZE];
    uint8_t rows;
    uint8_t columns;
} matrix_t;

#define MATRIX_OK           0x00
#define MATRIX_SINGULAR     0x01

void matrix_add(matrix_t *dest, const matrix_t *a, const matrix_t *b);
void matrix_sub(matrix_t *dest, const matrix_t *a, const matrix_t *b);
void matrix_mul(matrix_t *dest, const matrix_t *a, const matrix_t *b);
void matrix_mul_at(matrix_t *dest, const matrix_t *at, const matrix_t *b);
void matrix_tranpose(matrix_t *dest, const matrix_t *matrix);

int matrix_qr_decomposition(matrix_t *q, matrix_t *r, const matrix_t *matrix, int reorthogonalize);

// Solving a system of linear equations QRx = b.
int matrix_solve(matrix_t *dest, const matrix_t *q, const matrix_t *r, const matrix_t *matrix);

void matrix_fill(matrix_t *dest, MATRIX_TYPE value);
void matrix_print(matrix_t *matrix);

#endif
