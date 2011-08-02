#ifndef HAVE_ALGO_ROWWISE_HPP
#define HAVE_ALGO_ROWWISE_HPP

#include <mex.h>
#include <algorithm>

template <class T>
void swap_rows(T *adapt, size_t r1, size_t r2) {
  /*
   *
   */
  mxAssert(r1 < adapt->getRows(), "swap_rows(): row index out of bounds.");
  mxAssert(r2 < adapt->getRows(), "swap_rows(): row index out of bounds.");

  size_t ncols = adapt->getCols();
  for (size_t i = 0; i < ncols; ++i) {
    std::swap(adapt->operator()(r1, i), adapt->operator()(r2, i));
  }
}


template <class Op, class T>
void arith_rows(T *adapt, size_t r1, size_t r2) {
  /*
   *
   */
  mxAssert(r1 < adapt->getRows(), "arith_rows(): row index out of bounds.");
  mxAssert(r2 < adapt->getRows(), "arith_rows(): row index out of bounds.");

  size_t ncols = adapt->getCols();
  for (size_t i = 0; i < ncols; ++i) {
    adapt->operator()(r1, i) = Op::exec(adapt->operator()(r1, i),
                                        adapt->operator()(r2, i));
  }
}

#endif  // HAVE_ALGO_ROWWISE_HPP

