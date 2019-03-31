TARGETS := test_blas

CXXFLAGS := \
-I. \
-std=c++11

.PHONY: all
all: $(TARGETS)

test_blas: test_blas.cc
	$(CXX) $(CXXFLAGS) -o $@ $< -lblas

.PHONY: clean
clean:
	$(RM) $(TARGETS)

