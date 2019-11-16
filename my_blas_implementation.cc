/*  ---------------------------------------------------------------------
  Copyright 2018-2019 Fangjun Kuang
  email: csukuangfj at gmail dot com
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a COPYING file of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>
  -----------------------------------------------------------------  */

#include "my_blas_implementation.h"

#include <math.h>

namespace kk {
namespace level1 {

float sasum(const int N, const float *X, const int incX) {
  float s = 0;
  for (int i = 0; i < N; ++i) {
    s += fabs(*X);
    X += incX;
  }
  return s;
}

void saxpy(const int N, const float alpha, const float *X, const int incX,
           float *Y, const int incY) {
  for (int i = 0; i < N; ++i) {
    *Y += *X * alpha;
    X += incX;
    Y += incY;
  }
}

void scopy(const int N, const float *X, const int incX, float *Y,
           const int incY) {
  for (int i = 0; i < N; ++i) {
    *Y = *X;
    X += incX;
    Y += incY;
  }
}

float sdot(const int N, const float *X, const int incX, const float *Y,
           const int incY) {
  float p = 0;
  for (int i = 0; i < N; ++i) {
    p += (*X) * (*Y);
    X += incX;
    Y += incY;
  }
  return p;
}

float snrm2(const int N, const float *X, const int incX) {
  float s = 0;
  for (int i = 0; i < N; ++i) {
    s += (*X) * (*X);
    X += incX;
  }
  return sqrtf(s);
}

void sscal(const int N, const float alpha, float *X, const int incX) {
  for (int i = 0; i < N; ++i) {
    *X *= alpha;
    X += incX;
  }
}

void sswap(const int N, float *X, const int incX, float *Y, const int incY) {
  for (int i = 0; i < N; ++i) {
    float tmp = *X;
    *X = *Y;
    *Y = tmp;
    X += incX;
    Y += incY;
  }
}

CBLAS_INDEX isamax(const int N, const float *X, const int incX) {
  CBLAS_INDEX res = 0;
  float max_val = fabsf(*X);
  for (int i = 0; i < N; ++i) {
    if (fabsf(*X) > max_val) {
      res = i;  // is is the index of the element
      max_val = fabsf(*X);
    }
    X += incX;
  }
  return res;
}

}  // namespace level1

namespace level2 {

void sgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA,
           const int M, const int N, const float alpha, const float *A,
           const int lda, const float *X, const int incX, const float beta,
           float *Y, const int incY) {
  if (TransA == CblasNoTrans) {
    int num_rows = M;
    int num_cols = N;
    for (int r = 0; r < num_rows; ++r) {
      float row_sum = 0;
      for (int c = 0; c < num_cols; ++c) {
        if (order == CblasRowMajor) {
          // get the element of A at (r, c) for row major
          float value = A[r * lda + c];
          row_sum += value * X[c * incX];
        } else {
          // get the element of A at (r, c) for column major
          float value = A[r + c * lda];
          row_sum += value * X[c * incX];
        }
      }
      *Y = alpha * row_sum + beta * (*Y);

      // process the next row
      Y += incY;
    }
  } else {
    // we omit the case for CblasConjTrans
    // A is M-rows, N-cols
    // trans(A) is N-rows, M-cols
    // we want to compute y = alpha * trans(A) * x + beta * y

    int num_rows = N;
    int num_cols = M;
    for (int r = 0; r < num_rows; ++r) {
      float row_sum = 0;
      for (int c = 0; c < num_cols; ++c) {
        float value;
        if (order == CblasRowMajor) {
          // get the element (r, c) of TransA, which is (c, r) of A
          value = A[c * lda + r];
        } else {
          // for column major
          // get the element (r, c) of TransA, which is (c, r) of A
          value = A[c + r * lda];
        }
        row_sum += value * X[c * incX];
      }
      *Y = alpha * row_sum + beta * (*Y);

      // process the next row
      Y += incY;
    }
  }
}
}  // namespace level2

}  // namespace kk
