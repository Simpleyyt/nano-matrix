#include <math.h>
#include "array.h"

static MATRIX_TYPE array_abs(MATRIX_TYPE a) {
    return a > 0 ? a : -a;
}

MATRIX_TYPE array_dot(const MATRIX_TYPE *a, uint8_t a_stride, const MATRIX_TYPE *b, uint8_t b_stride, uint8_t n) {
    MATRIX_TYPE sum = 0;
    while (n--) {
        if (*a != 0 && *b != 0) {
            sum += (*a) * (*b);
        }
        a += a_stride;
        b += b_stride;
    }

    return sum;
}

MATRIX_TYPE array_norm(const MATRIX_TYPE *a, uint8_t a_stride, uint8_t n) {
    MATRIX_TYPE sum = 0;

    while (n--) {
        if (*a != 0) {
            sum += (*a) * (*a);
        }
        a += a_stride;
    }

    return sqrt(sum);
}
