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

/**
 * @brief An naive implemenation for the blas interface
 */

namespace kk {

namespace level1 {
/**
 * @defgroup level1 Level 1 functions.
 * @brief Level 1 functions in BLAS.
 *
 * @code
 * y = alpha * x + y
 * @endcode
 *
 * @note `x` and `y` can be the same; that is, it can be an inplace operation.
 *
 * Refer to
 * https://en.wikipedia.org/wiki/Basic_Linear_Algebra_Subprograms#Level_1 for
 * the classification of BLAS levels.
 *
 * @{
 */

/**
 *
 * @brief scale x with alpha.
 *
 * axpy
 *
 * @code
 * for i in range(N):
 *   X[i * incX] *= alpha
 * @endcode
 *
 * @param N number of elements in X
 * @param alpha the scale
 * @param X a vector
 * @param incX the stride between two elements in X
 *
 * @note `incX` can be **negative**
 * @warn this is an inplace operation
 *
 * Refer to
 * https://software.intel.com/en-us/mkl-developer-reference-c-cblas-scal
 */
void sscal(const int N, const float alpha, float *X, const int incX);

/** @} */
}  // namespace level1
}  // namespace kk
