#ifndef HAVE_MX_TRAITS_HPP
#define HAVE_MX_TRAITS_HPP

#include "mex.h"

template <class T>
struct mx_traits { };

// double
template<> struct mx_traits<double> {
    static const mxClassID classId = mxDOUBLE_CLASS;
};

template<> struct mx_traits<const double> {
    static const mxClassID classId = mxDOUBLE_CLASS;
};

// float
template<> struct mx_traits<float> {
    static const mxClassID classId = mxSINGLE_CLASS;
};

template<> struct mx_traits<const float> {
    static const mxClassID classId = mxSINGLE_CLASS;
};

// uint8
template<> struct mx_traits<uint8_t> {
    static const mxClassID classId = mxUINT8_CLASS;
};

template<> struct mx_traits<const uint8_t> {
    static const mxClassID classId = mxUINT8_CLASS;
};

// int8
template<> struct mx_traits<int8_t> {
    static const mxClassID classId = mxINT8_CLASS;
};

template<> struct mx_traits<const int8_t> {
    static const mxClassID classId = mxINT8_CLASS;
};

// uint16
template<> struct mx_traits<uint16_t> {
    static const mxClassID classId = mxUINT16_CLASS;
};

template<> struct mx_traits<const uint16_t> {
    static const mxClassID classId = mxUINT16_CLASS;
};

// int16
template<> struct mx_traits<int16_t> {
    static const mxClassID classId = mxINT16_CLASS;
};

template<> struct mx_traits<const int16_t> {
    static const mxClassID classId = mxINT16_CLASS;
};

// uint32
template<> struct mx_traits<uint32_t> {
    static const mxClassID classId = mxUINT32_CLASS;
};

template<> struct mx_traits<const uint32_t> {
    static const mxClassID classId = mxUINT32_CLASS;
};

// int32
template<> struct mx_traits<int32_t> {
    static const mxClassID classId = mxINT32_CLASS;
};

template<> struct mx_traits<const int32_t> {
    static const mxClassID classId = mxINT32_CLASS;
};

#endif
