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

#include <cassert>
#include <iostream>
#include <vector>

// cblas.h is from https://www.netlib.org/blas/cblas.h
#include "cblas.h"

#include "my_blas_implementation.h"

void test_cblas_sscal() {
  std::cout << "==========cblas_sscal==========" << std::endl;

  std::vector<float> x = {0, 1, 2, 3};
  std::vector<float> y = x;

  float alpha = 10;

  // case 1: incx is 1
  // scale every element of x by 10
  cblas_sscal(4, alpha, x.data(), 1);
  kk::level1::sscal(4, alpha, y.data(), 1);
  assert(x == y);

  assert(x[0] == 0);   // 0 * 10
  assert(x[1] == 10);  // 1 * 10
  assert(x[2] == 20);  // 2 * 10
  assert(x[3] == 30);  // 3 * 10

  // case 2: incx is 2
  // scale every second element of x by 100
  alpha = 100;
  cblas_sscal(2, alpha, x.data(), 2);
  kk::level1::sscal(2, alpha, y.data(), 2);
  assert(x == y);

  assert(x[0] == 0);
  assert(x[1] == 10);    // not changed
  assert(x[2] == 2000);  // scaled by 100, 20*100
  assert(x[3] == 30);    // not changed

  std::cout << "==========cblas_sscal OK==========" << std::endl;
}

#if 0
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
              CblasNoTrans,  // TransA no transpose for A
              2,             // M, number of rows in A
              3,             // N, number of columns in A
              1.,            // alpha, 1, no scale
              A,             // A
              3,             // lda
              x,             // x
              1,             // incX
              0.,            // beta
              y,             // y
              1              // incY
  );
  assert(y[0] == 8);
  assert(y[1] == 20);
  printf("y[0] = %.2f\n", y[0]);
  printf("y[1] = %.2f\n", y[1]);
}
#endif

int main() {
  test_cblas_sscal();
  return 0;
}
