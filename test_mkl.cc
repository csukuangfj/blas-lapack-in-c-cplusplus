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
#include <mkl_service.h>

namespace {
void print_mkl_version() {
  MKLVersion v;
  mkl_get_version(&v);
  std::cout << "Version: " << v.MajorVersion << v.MinorVersion
            << v.UpdateVersion << "\n";
  std::cout << "Product status: " << v.ProductStatus << "\n";
  std::cout << "Build: " << v.Build << "\n";
  std::cout << "Processor optimization: " << v.Processor << "\n";
  int len = 198;
  char buf[198];
  mkl_get_version_string(buf, len);
  std::cout << "version string: " << buf << "\n";
}

void test_cblas_sscal() {
  float* x = (float*)mkl_malloc(2 * sizeof(float), 64);  // 64 bytes alignment
  x[0] = 10;
  x[1] = 20;
  cblas_sscal(2, 10, x, 1);
  std::cout << "x[0]: " << x[0] << "\n";
  std::cout << "x[1]: " << x[1] << "\n";

  MKL_INT64 allocated_bytes;
  int num_allocated_buffers;
  allocated_bytes = mkl_mem_stat(&num_allocated_buffers);
  std::cout << "allocated_bytes: " << allocated_bytes << "\n";
  std::cout << "num_allocated_buffers: " << num_allocated_buffers << "\n";

  mkl_free(x);
  allocated_bytes = mkl_mem_stat(&num_allocated_buffers);
  std::cout << "allocated_bytes: " << allocated_bytes << "\n";
  std::cout << "num_allocated_buffers: " << num_allocated_buffers << "\n";
}
void test() {
  print_mkl_version();
  test_cblas_sscal();
}
}  // namespace

int main() { test(); }
