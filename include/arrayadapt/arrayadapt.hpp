#ifndef HAVE_ARRAYADAPT_ARRAYADAPT_HPP
#define HAVE_ARRAYADAPT_ARRAYADAPT_HPP

#include <stdint.h>
#include <matrix.h>
#include <mex.h>
#include "../mx_traits.hpp"
#include "./detail/get.hpp"
#include "./detail/factory.hpp"

namespace arrayadapt {
/*
 *
 */
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
    public detail::Getter<DataT, kDims, ArrayAdapter>,
    public detail::Factory<DataT, kDims, ArrayAdapter> {
      /*
       *
       */
     public:
      friend struct detail::Getter<DataT, kDims, arrayadapt::ArrayAdapter>;
      friend struct detail::Factory<DataT, kDims, arrayadapt::ArrayAdapter>;

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
}  // namespace arrayadapt

#endif  // HAVE_ARRAYADAPT_ARRAYADAPT_HPP

