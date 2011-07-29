#ifndef HAVE_ARRAYADAPT_TYPES_HPP
#define HAVE_ARRAYADAPT_TYPES_HPP

// float/double
typedef ArrayAdapter<double, 1> double_vector;
typedef ArrayAdapter<const double, 1> const_double_vector;

typedef ArrayAdapter<double, 2> double_matrix;
typedef ArrayAdapter<const double, 2> const_double_matrix;

typedef ArrayAdapter<float, 1> float_vector;
typedef ArrayAdapter<const float, 1> const_float_vector;

typedef ArrayAdapter<float, 2> float_matrix;
typedef ArrayAdapter<const float, 2> const_float_matrix;

// (u)int8_t
typedef ArrayAdapter<uint8_t, 1> uint8_vector;
typedef ArrayAdapter<const uint8_t, 1> const_uint8_vector;

typedef ArrayAdapter<uint8_t, 2> uint8_matrix;
typedef ArrayAdapter<const uint8_t, 2> const_uint8_matrix;

typedef ArrayAdapter<int8_t, 1> int8_vector;
typedef ArrayAdapter<const int8_t, 1> const_int8_vector;

typedef ArrayAdapter<int8_t, 2> int8_matrix;
typedef ArrayAdapter<const int8_t, 2> const_int8_matrix;

// (u)int16_t
typedef ArrayAdapter<uint16_t, 1> uint16_vector;
typedef ArrayAdapter<const uint16_t, 1> const_uint16_vector;

typedef ArrayAdapter<uint16_t, 2> uint16_matrix;
typedef ArrayAdapter<const uint16_t, 2> const_uint16_matrix;

typedef ArrayAdapter<int16_t, 1> int16_vector;
typedef ArrayAdapter<const int16_t, 1> const_int16_vector;

typedef ArrayAdapter<int16_t, 2> int16_matrix;
typedef ArrayAdapter<const int16_t, 2> const_int16_matrix;

// (u)int32_t
typedef ArrayAdapter<uint32_t, 1> uint32_vector;
typedef ArrayAdapter<const uint32_t, 1> const_uint32_vector;

typedef ArrayAdapter<uint32_t, 2> uint32_matrix;
typedef ArrayAdapter<const uint32_t, 2> const_uint32_matrix;

typedef ArrayAdapter<int32_t, 1> int32_vector;
typedef ArrayAdapter<const int32_t, 1> const_int32_vector;

typedef ArrayAdapter<int32_t, 2> int32_matrix;
typedef ArrayAdapter<const int32_t, 2> const_int32_matrix;

#endif // HAVE_ARRAYADAPT_TYPES_HPP

