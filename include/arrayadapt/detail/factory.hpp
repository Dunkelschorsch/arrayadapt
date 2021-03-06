#ifndef HAVE_DETAIL_FACTORY_HPP
#define HAVE_DETAIL_FACTORY_HPP

namespace arrayadapt {
/*
 *
 */
namespace detail {
/*
 *
 */
template  <class DataT, size_t kDims, template<class, size_t> class AdapterT>
struct Factory { };

template  <class DataT, template<class, size_t> class AdapterT>
struct Factory<DataT, 1, AdapterT> {
  /*
   *
   */
  typedef AdapterT<DataT, 1> concrete_adapter_t;

  template <class RealOrImag>
  static inline concrete_adapter_t wrap(const mxArray* u, size_t length) {
    mxAssert(mxGetClassID(u) == mx_traits<DataT>::classId,
             "ArrayAdapter::wrap(): differing Matlab/C types");
    return wrap(RealOrImag::get_ptr(u), length);
  }

  static inline concrete_adapter_t wrap(void* const mxarray, size_t length) {
    mxAssert(length > 0,
             "ArrayAdapter::wrap(): zero-size dimension (1 of 1) given");

    concrete_adapter_t a(mxarray);
    a.dimensions[0] = length;
    return a;
  }
};  // struct Factory<DataT, 1, AdapterT>

template  <class DataT, template<class, size_t> class AdapterT>
struct Factory<DataT, 2, AdapterT> {
  /*
   *
   */
  typedef AdapterT<DataT, 2> concrete_adapter_t;

  template <class RealOrImag>
  static inline concrete_adapter_t wrap(const mxArray* u, size_t nrows, size_t ncols) {
    mxAssert(mxGetClassID(u) == mx_traits<DataT>::classId,
             "ArrayAdapter::wrap(): differing Matlab/C types");
    mxAssert(mxGetNumberOfDimensions(u) == 2,
             "ArrayAdapter::wrap(): wrong number of dimensions");

    return wrap(RealOrImag::get_ptr(u), nrows, ncols);
  }

  static inline concrete_adapter_t wrap(void* const mxarray, size_t nrows, size_t ncols) {
    mxAssert(nrows > 0,
             "ArrayAdapter::wrap(): zero-size dimension (1 of 2) given");
    mxAssert(ncols > 0,
             "ArrayAdapter::wrap(): zero-size dimension (2 of 2) given");

    concrete_adapter_t a(mxarray);
    a.dimensions[0] = nrows;
    a.dimensions[1] = ncols;
    return a;
  }
};  // struct Factory<DataT, 2, AdapterT>

template  <class DataT, template<class, size_t> class AdapterT>
struct Factory<DataT, 3, AdapterT> {
  /*
   *
   */
  typedef AdapterT<DataT, 3> concrete_adapter_t;

  template <class RealOrImag>
  static inline concrete_adapter_t wrap(const mxArray* u,
                                        size_t d1,
                                        size_t d2,
                                        size_t d3) {
    mxAssert(mxGetClassID(u) == mx_traits<DataT>::classId,
             "ArrayAdapter::wrap(): differing Matlab/C types");
    mxAssert(mxGetNumberOfDimensions(u) == 3,
             "ArrayAdapter::wrap(): wrong number of dimensions");

    return wrap(RealOrImag::get_ptr(u), d1, d2, d3);
  }

  static inline concrete_adapter_t wrap(void* const mxarray,
                                        size_t d1,
                                        size_t d2,
                                        size_t d3) {
    mxAssert(d1 > 0,
             "ArrayAdapter::wrap(): zero-size dimension (1 of 3) given ");
    mxAssert(d2 > 0,
             "ArrayAdapter::wrap(): zero-size dimension (2 of 3) given ");
    mxAssert(d3 > 0,
             "ArrayAdapter::wrap(): zero-size dimension (3 of 3) given ");

    concrete_adapter_t a(mxarray);
    a.dimensions[0] = d1;
    a.dimensions[1] = d2;
    a.dimensions[2] = d3;
    return a;
  }
};  // struct Factory<DataT, 3, AdapterT>
}  // namespace detail
}  // namespace arrayadapt

#endif  // HAVE_DETAIL_FACTORY_HPP
