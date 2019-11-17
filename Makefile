# Copyright 2019. All Rights Reserved.
# Author: csukuangfj at gmail.com (Fangjun Kuang)

# -I. for cblas.h (downloaded from https://www.netlib.org/blas/cblas.h)
CXXFLAGS := -I. -std=c++11
CXXFLAGS += -DNDEBUG -O3 -pthread -march=native -flto


.PHONY: all
all: test_blas
	@echo "run test"
	./test_blas

test_blas: test_blas.cc my_blas_implementation.cc
	$(CXX) $(CXXFLAGS) -o $@ $^ -lblas

MKL_INSTALL_DIR := $(HOME)/software/mkl
MKL_ROOT := $(MKL_INSTALL_DIR)/mkl
RPATH := -Wl,-rpath,$(MKL_ROOT)/lib

# there are lot of options to link mkl,
# refer to https://github.com/shawfdong/hyades/wiki/Intel-MKL
LDFLAGS := -L$(MKL_ROOT)/lib -lmkl_intel_lp64 -lmkl_core -lmkl_sequential
CXXFLAGS += -I$(MKL_ROOT)/include

test_mkl: test_mkl.cc
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(RPATH)
	./test_mkl

.PHONY: clean
clean:
	$(RM) test_blas test_mkl

