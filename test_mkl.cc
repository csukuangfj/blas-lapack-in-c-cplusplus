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
#include <iostream>

#include <mkl.h>

int main() {
  float* x = (float*)mkl_malloc(2 * sizeof(float), 64);  // 64 bytes alignment
  x[0] = 10;
  x[1] = 20;
  cblas_sscal(2, 10, x, 1);
  std::cout << "x[0]: " << x[0] << "\n";
  std::cout << "x[1]: " << x[1] << "\n";

  mkl_free(x);
}
