#ifndef HAVE_MX_TRAITS_HPP
#define HAVE_MX_TRAITS_HPP

#include <mex.h>

template <class T>
struct mx_traits { };

// void
template<> struct mx_traits<void> {
  static const mxClassID classId = mxVOID_CLASS;

  static inline const char* name() {
    return "void";
  }
};

// const void
template<> struct mx_traits<const void> {
  static const mxClassID classId = mxVOID_CLASS;

  static inline const char* name() {
    return "const void";
  }
};

// bool
template<> struct mx_traits<bool> {
  static const mxClassID classId = mxLOGICAL_CLASS;

  static inline const char* name() {
    return "bool";
  }
};

// const bool
template<> struct mx_traits<const bool> {
  static const mxClassID classId = mxLOGICAL_CLASS;

  static inline const char* name() {
    return "const bool";
  }
};

// double
template<> struct mx_traits<double> {
  static const mxClassID classId = mxDOUBLE_CLASS;

  static inline const char* name() {
    return "double";
  }
};

// const double
template<> struct mx_traits<const double> {
  static const mxClassID classId = mxDOUBLE_CLASS;

  static inline const char* name() {
    return "const double";
  }
};

// float
template<> struct mx_traits<float> {
  static const mxClassID classId = mxSINGLE_CLASS;

  static inline const char* name() {
    return "float";
  }
};

// const float
template<> struct mx_traits<const float> {
  static const mxClassID classId = mxSINGLE_CLASS;

  static inline const char* name() {
    return "const float";
  }
};

// uint64_t
template<> struct mx_traits<uint64_t> {
  static const mxClassID classId = mxUINT64_CLASS;

  static inline const char* name() {
    return "uint64_t";
  }
};

// const uint64_t
template<> struct mx_traits<const uint64_t> {
  static const mxClassID classId = mxUINT64_CLASS;

  static inline const char* name() {
    return "const uint64_t";
  }
};

// int64_t
template<> struct mx_traits<int64_t> {
  static const mxClassID classId = mxINT64_CLASS;

  static inline const char* name() {
    return "int64_t";
  }
};

// const int64_t
template<> struct mx_traits<const int64_t> {
  static const mxClassID classId = mxINT64_CLASS;

  static inline const char* name() {
    return "const int64_t";
  }
};

// uint32_t
template<> struct mx_traits<uint32_t> {
  static const mxClassID classId = mxUINT32_CLASS;

  static inline const char* name() {
    return "uint32_t";
  }
};

// const uint32_t
template<> struct mx_traits<const uint32_t> {
  static const mxClassID classId = mxUINT32_CLASS;

  static inline const char* name() {
    return "const uint32_t";
  }
};

// int32_t
template<> struct mx_traits<int32_t> {
  static const mxClassID classId = mxINT32_CLASS;

  static inline const char* name() {
    return "int32_t";
  }
};

// const int32_t
template<> struct mx_traits<const int32_t> {
  static const mxClassID classId = mxINT32_CLASS;

  static inline const char* name() {
    return "const int32_t";
  }
};

// uint16_t
template<> struct mx_traits<uint16_t> {
  static const mxClassID classId = mxUINT16_CLASS;

  static inline const char* name() {
    return "uint16_t";
  }
};

// const uint16_t
template<> struct mx_traits<const uint16_t> {
  static const mxClassID classId = mxUINT16_CLASS;

  static inline const char* name() {
    return "const uint16_t";
  }
};

// int16_t
template<> struct mx_traits<int16_t> {
  static const mxClassID classId = mxINT16_CLASS;

  static inline const char* name() {
    return "int16_t";
  }
};

// const int16_t
template<> struct mx_traits<const int16_t> {
  static const mxClassID classId = mxINT16_CLASS;

  static inline const char* name() {
    return "const int16_t";
  }
};

// uint8_t
template<> struct mx_traits<uint8_t> {
  static const mxClassID classId = mxUINT8_CLASS;

  static inline const char* name() {
    return "uint8_t";
  }
};

// const uint8_t
template<> struct mx_traits<const uint8_t> {
  static const mxClassID classId = mxUINT8_CLASS;

  static inline const char* name() {
    return "const uint8_t";
  }
};

// int8_t
template<> struct mx_traits<int8_t> {
  static const mxClassID classId = mxINT8_CLASS;

  static inline const char* name() {
    return "int8_t";
  }
};

// const int8_t
template<> struct mx_traits<const int8_t> {
  static const mxClassID classId = mxINT8_CLASS;

  static inline const char* name() {
    return "const int8_t";
  }
};

#endif  // HAVE_MX_TRAITS_HPP
