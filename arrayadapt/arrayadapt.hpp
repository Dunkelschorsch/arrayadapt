/* 
 * Copyright (c) 2011 Armin C. Schmidt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef HAVE_ARRAYADAPT_ARRAYADAPT_HPP
#define HAVE_ARRAYADAPT_ARRAYADAPT_HPP

#include <stdint.h>
#include <matrix.h>
#include <mex.h>
#include <mx_traits.hpp>
#include "./detail/get.hpp"
#include "./detail/factory.hpp"

namespace ptr_access {
/*
 *
 */
struct real {
  static inline double* get_ptr(const mxArray *u) {
    return mxGetPr(u);
  }
};

struct imag {
  static inline double* get_ptr(const mxArray *u) {
    return mxGetPi(u);
  }
};
}  // namespace ptr_access


template <class DataT, size_t kDims>
class ArrayAdapter :
    public detail::Getter<DataT, kDims, ArrayAdapter >,
    public detail::Factory<DataT, kDims, ArrayAdapter > {
      /*
       *
       */
     public:
      friend class detail::Getter<DataT, kDims, ArrayAdapter >;
      friend class detail::Factory<DataT, kDims, ArrayAdapter >;

      typedef DataT value_type;

      ArrayAdapter() { }

      // BEWARE!! this guy does not do any bounds checking, even in debug mode!
      inline DataT& operator[](size_t i) const {
        return mat_[i];
      }

     protected:
      explicit ArrayAdapter(void* const mat) : mat_(static_cast<DataT*>(mat)) { }

      DataT *mat_;
      size_t dimensions[kDims];
      static const size_t num_dims = kDims;
    };

#endif  // HAVE_ARRAYADAPT_ARRAYADAPT_HPP

