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

#include <cstdint>

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
 * y = sum(abs(x[:]))
 * y = alpha * x + y
 * y = x
 * y = alpha * y
 * s = dot(x, y)
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
 * @brief Sum of the absolute values of a vector: y = sum(abs(x[:]))
 *
 * @param N number of elements in `X`
 * @param X the vector
 * @param incX the stride in `X`
 *
 * @return the sum of absolute value of all elements in `X`
 *
 * @warning **a** in **sasum** means **absolute**
 *
 * Refer to
 * - https://software.intel.com/en-us/onemkl-developer-reference-c-cblas-asum
 * - http://www.netlib.org/blas/sasum.f
 */
float sasum(const int N, const float *X, const int incX);

/** @brief Y = alpha * X + Y
 *
 * axpy is short for a*x plus y
 *
 * @param N number of elements in X and Y
 * @param alpha the scale
 * @param X the vector X
 * @param incX the stride for `X`
 * @param Y the vector Y
 * @param incY the stride for `Y`
 *
 * Refer to
 * - https://software.intel.com/en-us/onemkl-developer-reference-c-cblas-axpy
 * - http://www.netlib.org/blas/saxpy.f
 */

void saxpy(const int N, const float alpha, const float *X, const int incX,
           float *Y, const int incY);

/** @brief copy a vector: y = x
 *
 * @param N number of elements in `X`
 * @param X the src vector
 * @param incX the stride in `X`
 * @param Y the dst vector
 * @param incY the stride in `Y`
 *
 * Refer to
 * - https://software.intel.com/en-us/onemkl-developer-reference-c-cblas-copy
 * - http://www.netlib.org/blas/scopy.f
 */
void scopy(const int N, const float *X, const int incX, float *Y,
           const int incY);

/** @brief dot product of a vector: s = dot(x, y)
 *
 * Compute the dot product of two vectors.
 *
 * @param N number of elements in `X` and `Y`
 * @param X the vector `X`
 * @param incX the stride of vector `X`
 * @param Y the vector `Y`
 * @param incY the stride of vector `Y`
 *
 * Refer to
 * - https://software.intel.com/en-us/onemkl-developer-reference-c-cblas-dot
 * - http://www.netlib.org/blas/sdot.f
 *
 */
float sdot(const int N, const float *X, const int incX, const float *Y,
           const int incY);

/** @brief Return the 2-norm of a vector.
 *
 * Compute s = sqrt(dot(X, X))
 *
 * @param N number of elements in the vector `X`
 * @param X the vector
 * @param incX the stride in `X`
 * @return sqrt(dot(X, X))
 *
 * Refer to
 * - https://software.intel.com/en-us/onemkl-developer-reference-c-cblas-nrm2
 * - http://www.netlib.org/blas/snrm2.f
 */
float snrm2(const int N, const float *X, const int incX);

/** @brief scale x with alpha.
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
 * @warning this is an inplace operation
 *
 * Refer to
 * - https://software.intel.com/en-us/mkl-developer-reference-c-cblas-scal
 * - http://www.netlib.org/blas/sscal.f
 */
void sscal(const int N, const float alpha, float *X, const int incX);

/** @brief swap two vectors
 *
 * @param N number of elements in `X` and `Y`
 * @param X the vector `X`
 * @param incX the stride in `X`
 * @param Y the vector `Y`
 * @param incY the stride in `Y`
 *
 * Refer to
 * - https://software.intel.com/en-us/onemkl-developer-reference-c-cblas-swap
 * - http://www.netlib.org/blas/sswap.f
 */
void sswap(const int N, float *X, const int incX, float *Y, const int incY);

/** @brief Return the index `i` such that `abs(X[i*incX])` is the maximum.
 *
 * The naming convention of `isamax`
 * - `i`: the return value is an integer
 * - `s`: single float precision
 * - `amax`: short for **a**bsolute max
 *
 * Example: for an array `[0, 1, 2, -3]`
 * - if N = 4, incX=1, then it returns 3 (zero based index, the largest
 * **absolute** value 3 is at position 3, [0, 1, 2, -3])
 * - if N = 2, incX=2, then it returns 1 (zero based index, the largest
 * **absolute** value 2 is at position 1, with stride 2, [0, 2])
 *
 * @param N number of elements in `X`
 * @param X the vector X
 * @param incX the stride in `X`
 *
 * @return the index `i` such that `X[i*incX]` is the maximum
 *
 * @warning it should be CBLAS_INDEX, which is platform dependent macro
 */
size_t isamax(const int N, const float *X, const int incX);

/** @} */
}  // namespace level1
}  // namespace kk
