#ifndef HAVE_DETAIL_GET_HPP
#define HAVE_DETAIL_GET_HPP

namespace arrayadapt {
/*
 *
 */
namespace detail {
/*
 *
 */
template <class DataT, size_t kDims, template<class, size_t> class AdapterT>
struct Getter { };

template <class DataT, template<class, size_t> class AdapterT>
struct Getter<DataT, 1, AdapterT> {
  /*
   *
   */
  typedef AdapterT<DataT, 1> concrete_adaptor_t;

  inline DataT& operator()(size_t i) const {
    mxAssert(i < getLen(), "ArrayAdapter::operator(): element index out of bounds.");

    return static_cast<const concrete_adaptor_t*>(this)->mat_[i];
  }

  inline size_t getLen() const {
    return static_cast<const concrete_adaptor_t*>(this)->dimensions[0];
  }
};  // struct Getter<DataT, 1, AdapterT>


template <class DataT, template<class, size_t> class AdapterT>
struct Getter<DataT, 2, AdapterT> {
  /*
   *
   */
  typedef AdapterT<DataT, 2> concrete_adaptor_t;
  
  inline DataT& operator()(size_t i, size_t j) const {
    mxAssert(i < getRows(), "ArrayAdapter::operator(): row index out of bounds.");
    mxAssert(j < getCols(), "ArrayAdapter::operator(): column index out of bounds.");

    return static_cast<const concrete_adaptor_t*>(this)->mat_[i + getRows() * j];
  }

  inline size_t getRows() const {
    return static_cast<const concrete_adaptor_t*>(this)->dimensions[0];
  }

  inline size_t getCols() const {
    return static_cast<const concrete_adaptor_t*>(this)->dimensions[1];
  }
};  // struct Getter<DataT, 2, AdapterT>


template <class DataT, template<class, size_t> class AdapterT>
struct Getter<DataT, 3, AdapterT> {
  /*
   *
   */
typedef AdapterT<DataT, 3> concrete_adaptor_t;

  inline DataT& operator()(size_t i, size_t j, size_t k) const {
    mxAssert(i < getDim<0>(),
             "ArrayAdapter::operator(): index for dimension 1 out of bounds.");
    mxAssert(i < getDim<1>(),
             "ArrayAdapter::operator(): index for dimension 2 out of bounds.");
    mxAssert(i < getDim<2>(),
             "ArrayAdapter::operator(): index for dimension 3 out of bounds.");

    return static_cast<const concrete_adaptor_t*>(this)->
        mat_[i + getDim<0>() * (j + k * getDim<1>())];
  }

  template <size_t D>
  inline size_t getDim() const {
    return static_cast<const concrete_adaptor_t*>(this)->dimensions[D];
  }
};  // struct Getter<DataT, 3, AdapterT>
}  // namespace detail
}  // namespace arrayadapt

#endif  // HAVE_DETAIL_GET_HPP

