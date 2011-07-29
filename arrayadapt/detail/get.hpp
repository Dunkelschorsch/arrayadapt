#ifndef HAVE_DETAIL_GET_HPP
#define HAVE_DETAIL_GET_HPP

namespace detail {

template <size_t kDims, class DataT, class AdapterT>
struct Getter { };

template <class DataT, class AdapterT>
struct Getter<1, DataT, AdapterT> {
  /*
   *
   */
  inline DataT& operator()(size_t i) const {
    mxAssert(i < getLen(), "operator(): element index out of bounds.");

    return static_cast<const AdapterT*>(this)->mat_[i];
  }

  inline size_t getLen() const {
    return static_cast<const AdapterT*>(this)->dimensions[0];
  }
};  // struct Getter<1, DataT, AdapterT>


template <class DataT, class AdapterT>
struct Getter<2, DataT, AdapterT> {
  /*
   *
   */
  inline DataT& operator()(size_t i, size_t j) const {
    mxAssert(i < getRows(), "operator(): row index out of bounds.");
    mxAssert(j < getCols(), "operator(): column index out of bounds.");

    return static_cast<const AdapterT*>(this)->mat_[i + getRows() * j];
  }

  inline size_t getRows() const {
    return static_cast<const AdapterT*>(this)->dimensions[0];
  }

  inline size_t getCols() const {
    return static_cast<const AdapterT*>(this)->dimensions[1];
  }
};  // struct Getter<2, DataT, AdapterT>


template <class DataT, class AdapterT>
struct Getter<3, DataT, AdapterT> {
  /*
   *
   */
  inline DataT& operator()(size_t i, size_t j, size_t k) const {
    mxAssert(i < getDim<0>(),
             "operator(): index for dimension 1 out of bounds.");
    mxAssert(i < getDim<1>(),
             "operator(): index for dimension 2 out of bounds.");
    mxAssert(i < getDim<2>(),
             "operator(): index for dimension 3 out of bounds.");

    return static_cast<const AdapterT*>(this)->
        mat_[i + getDim<0>() * (j + k * getDim<1>())];
  }

  template <size_t D>
  inline size_t getDim() const {
    return static_cast<const AdapterT*>(this)->dimensions[D];
  }
};  // struct Getter<3, DataT, AdapterT>
}  // namespace detail

#endif  // HAVE_DETAIL_GET_HPP

