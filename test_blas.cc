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
#include <cstdint>
#include <iostream>
#include <vector>

// cblas.h is from https://www.netlib.org/blas/cblas.h
#include "cblas.h"

#include "my_blas_implementation.h"

void test_cblas_sasum() {
  std::cout << "==========cblas_sasum==========" << std::endl;
  std::vector<float> x = {-1, -2, 3, 4};
  std::vector<float> y = x;
  float sx = cblas_sasum(x.size(), x.data(), 1);
  float sy = kk::level1::sasum(y.size(), y.data(), 1);
  assert(sx == sy);
  assert(sx == (1 + 2 + 3 + 4));
  std::cout << "==========cblas_sasum OK=======" << std::endl;
}

void test_cblas_saxpy() {
  std::cout << "==========cblas_saxpy==========" << std::endl;
  std::vector<float> x1 = {1, 2, 3, 4};
  std::vector<float> y1 = {10, 10, 20, 30};

  std::vector<float> x2 = x1;
  std::vector<float> y2 = y1;

  float alpha = 10;

  // stride 1
  cblas_saxpy(x1.size(), alpha, x1.data(), 1, y1.data(), 1);
  kk::level1::saxpy(x2.size(), alpha, x2.data(), 1, y2.data(), 1);
  assert(y1 == y2);
  std::cout << "==========cblas_saxpy OK=======" << std::endl;
}

void test_cblas_scopy() {
  std::cout << "==========cblas_scopy==========" << std::endl;
  std::vector<float> x1 = {-1, -2, 3, 4};
  std::vector<float> x2 = x1;

  std::vector<float> y1(x1.size());
  std::vector<float> y2(x2.size());

  cblas_scopy(x1.size(), x1.data(), 1, y1.data(), 1);
  kk::level1::scopy(x2.size(), x2.data(), 1, y2.data(), 1);
  assert(y1 == y2);
  std::cout << "==========cblas_scopy OK=======" << std::endl;
}

void test_cblas_sdot() {
  std::cout << "==========cblas_sdot===========" << std::endl;
  std::vector<float> x1 = {-1, -2, 3, 4};
  std::vector<float> y1 = {10, 20, 30, 40};

  std::vector<float> x2 = x1;
  std::vector<float> y2 = y1;

  float p1 = cblas_sdot(x1.size(), x1.data(), 1, y1.data(), 1);
  float p2 = kk::level1::sdot(x2.size(), x2.data(), 1, y2.data(), 1);
  assert(p1 == p2);
  std::cout << "==========cblas_sdot OK========" << std::endl;
}

void test_cblas_snrm2() {
  std::cout << "==========cblas_snrm2==========" << std::endl;
  std::vector<float> x = {-1, -2, 3, 4};
  std::vector<float> y = x;

  float n1 = cblas_snrm2(x.size(), x.data(), 1);
  float n2 = kk::level1::snrm2(y.size(), y.data(), 1);
  assert(n1 == n2);
  std::cout << "==========cblas_snrm2 OK=======" << std::endl;
}

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

  std::cout << "==========cblas_sscal OK=======" << std::endl;
}

void test_cblas_sswap() {
  std::cout << "==========cblas_sswap==========" << std::endl;
  std::vector<float> x1 = {-1, -2, 3, 4};
  std::vector<float> y1 = {10, 20, 30, 40};

  std::vector<float> x2 = x1;
  std::vector<float> y2 = y1;

  std::vector<float> x = x1;
  std::vector<float> y = y1;

  cblas_sswap(x1.size(), x1.data(), 1, y1.data(), 1);
  kk::level1::sswap(x2.size(), x2.data(), 1, y2.data(), 1);
  assert(x1 == y);
  assert(y1 == x);

  assert(x2 == y);
  assert(y2 == x);
  std::cout << "==========cblas_sswap OK=======" << std::endl;
}

//! absolute maximum
void test_cblas_isamax() {
  std::cout << "==========cblas_isamax=========" << std::endl;
  std::vector<float> x{0, 1, 2, 3, 4, 5, -6, -7};
  size_t m1 = cblas_isamax(8, x.data(), 1);  // count from index 0
  size_t m2 = kk::level1::isamax(8, x.data(), 1);
  assert(m1 == m2);
  assert(m1 == 7);

  // now for stride == 2
  m1 = cblas_isamax(4, x.data(), 2);
  m2 = kk::level1::isamax(4, x.data(), 2);
  assert(m1 == m2);
  assert(m1 == 3);
  std::cout << "==========cblas_isamax OK======" << std::endl;
}

int main() {
  test_cblas_sasum();
  test_cblas_saxpy();
  test_cblas_scopy();
  test_cblas_sdot();
  test_cblas_snrm2();
  test_cblas_sscal();
  test_cblas_sswap();
  test_cblas_isamax();
  return 0;
}
