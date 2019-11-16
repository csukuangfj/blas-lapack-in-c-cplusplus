# Copyright 2019. All Rights Reserved.
# Author: csukuangfj at gmail.com (Fangjun Kuang)

# -I. for cblas.h (downloaded from https://www.netlib.org/blas/cblas.h)
CXXFLAGS := -I. -std=c++11

.PHONY: all
all: test_blas
	@echo "run test"
	./test_blas

test_blas: test_blas.cc my_blas_implementation.cc
	$(CXX) $(CXXFLAGS) -o $@ $^ -lblas

.PHONY: clean
clean:
	$(RM) test_blas

