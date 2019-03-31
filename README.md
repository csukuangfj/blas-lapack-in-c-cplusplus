
## Introduction

This repository contains little examples for using
BLAS/Lapack in C/C++. It can be used to build
a large library for numerical linear algebra.

## BLAS

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

## References

- [GSL CBLAS Library][2]
- [Intel® Math Kernel Library (Intel® MKL) - BLAS, CBLAS and LAPACK Compiling/Linking Functions &Fortran and C/C++ Calls][1]
- https://developer.apple.com/documentation/accelerate/blas?language=objc


[2]: https://www.gnu.org/software/gsl/doc/html/cblas.html
[1]: https://software.intel.com/en-us/articles/intel-math-kernel-library-intel-mkl-blas-cblas-and-lapack-compilinglinking-functions-fortran-and-cc-calls#1

