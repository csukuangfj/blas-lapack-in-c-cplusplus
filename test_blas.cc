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
#include <stdio.h>

#include <cassert>

#include "cblas.h"

namespace {

// Matrix Vector multiplication
// y = alpha * A * x + beta * y
// A may be transposed
// https://developer.apple.com/documentation/accelerate/1513338-cblas_dgemv?language=objc
// 3 1 3     1      8
//        *  2
// 1 5 9     1  =   20
void test_dgemv() {
  // clang-format off
  double A[] = {
    3, 1, 3,
    1, 5, 9,
  };
  double x[] = {1, 2, 1};
  // clang-format on
  double y[2] = {0};

  // y = alpha * A * x + beta * y
  cblas_dgemv(CblasRowMajor,
              CblasNoTrans, // TransA no transpose for A
              2,            // M, number of rows in A
              3,            // N, number of columns in A
              1.,           // alpha, 1, no scale
              A,            // A
              3,            // lda
              x,            // x
              1,            // incX
              0.,           // beta
              y,            // y
              1             // incY
  );
  assert(y[0] == 8);
  assert(y[1] == 20);
  printf("y[0] = %.2f\n", y[0]);
  printf("y[1] = %.2f\n", y[1]);
}

} // namespace

int main() {
  test_dgemv();
  return 0;
}
