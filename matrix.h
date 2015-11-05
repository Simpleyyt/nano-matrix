#ifndef MATRIX_H
#define MATRIX_H

#ifndef MATRIX_TYPE
#define MATRIX_TYPE double
#endif

#ifndef MATRIX_SIZE
#define MATRIX_SIZE 4
#endif

#include <stdint.h>

typedef struct {
    MATRIX_TYPE data[MATRIX_SIZE][MATRIX_SIZE];
    uint8_t rows;
    uint8_t columns;
} matrix_t;


void matrix_add(matrix_t *dest, const matrix_t *a, const matrix_t *b);
void matrix_sub(matrix_t *dest, const matrix_t *a, const matrix_t *b);
void matrix_mul(matrix_t *dest, const matrix_t *a, const matrix_t *b);
void matrix_tranpose(matrix_t *dest, const matrix_t *matrix);

void matrix_print(matrix_t *matrix);

#endif
