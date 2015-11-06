#ifndef ARRAY_H
#define ARRAY_H

#include "matrix.h"

MATRIX_TYPE array_dot(const MATRIX_TYPE *a, uint8_t a_stride,
                      const MATRIX_TYPE *b, uint8_t b_stride,
                      uint8_t n);

MATRIX_TYPE array_norm(const MATRIX_TYPE *a, uint8_t a_stride, uint8_t n);

#endif
