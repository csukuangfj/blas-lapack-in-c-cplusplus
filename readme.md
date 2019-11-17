## Table of contents

- [Introduction](#introduction)
- [cblas.h](#cblas)
- [MKL](#mkl)
- [Documentation](#documentation)
- [References](#references)

## Introduction

This [repository][5] contains little examples for using
BLAS/Lapack in C/C++. It can be used to build
a large library for numerical linear algebra.

A straightforward reference implementation of the BLAS
interface is provided in [my_blas_implementation.h][4] (still on-going).

## cblas

The header file `cblas.h` can be obtained via

```sh
wget http://www.netlib.org/blas/cblas.h
```

On macOS, we have to link to `-lblas`, which resolves to

```sh
$ otool -L test_blas
test_blas:
  /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libBLAS.dylib (compatibility version 1.0.0, current version 1.0.0)
  /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 120.1.0)
  /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1226.10.1)
```

## MKL

Refer to [./install-mkl.md][9] for installing MKL on macOS.


## Documentation

We use [Doxygen][3] for documentation generation.

To install doxygen on macOS, use

```sh
brew install doxygen
```

or install it from source.

To generate documentation for this repository, run

```sh
./run-doxygen.sh
```
and you'll get the html pages under the directory `doxygen/html`.

You can find the generated documentation [here][6].

## References

- https://www.netlib.org/blas/
- [Intel(R) Math Kernel Library (Intel(R) MKL) Documentation], doc from scc.ustc.edu.cn

- [GSL CBLAS Library][2]
- [Intel® Math Kernel Library (Intel® MKL) - BLAS, CBLAS and LAPACK Compiling/Linking Functions &Fortran and C/C++ Calls][1]
- https://developer.apple.com/documentation/accelerate/blas?language=objc
- [Routines for BLAS, LAPACK, MAGMA][7]
- [Intel® Math Kernel Library Developer Reference][8] pdf
- [Intel® Math Kernel Library for Linux OS User Guide][11] pdf
- [Intel® Math Kernel Library for macOS Developer Guide][12], pdf

[12]: https://jp.xlsoft.com/documents/intel/mkl/2017/mkl_2017_osx_devguide.pdf
[11]: http://registrationcenter.intel.com/irc_nas/2690/mkl_userguide_lnx.pdf
[10]: https://scc.ustc.edu.cn/zlsc/sugon/intel/mkl/mkl_documentation.htm
[9]: https://github.com/csukuangfj/blas-lapack-in-c-cplusplus/blob/master/install-mkl.md
[8]: https://software.intel.com/sites/default/files/mkl-2019-developer-reference-c_3.pdf
[7]: http://www.icl.utk.edu/~mgates3/docs/lapack.html
[6]: https://csukuangfj.github.io/doc/blas-lapack-in-c-cplusplus/index.html
[5]: https://github.com/csukuangfj/blas-lapack-in-c-cplusplus
[4]: https://github.com/csukuangfj/blas-lapack-in-c-cplusplus/blob/master/my_blas_implementation.h
[3]: http://www.doxygen.nl/manual/
[2]: https://www.gnu.org/software/gsl/doc/html/cblas.html
[1]: https://software.intel.com/en-us/articles/intel-math-kernel-library-intel-mkl-blas-cblas-and-lapack-compilinglinking-functions-fortran-and-cc-calls#1

