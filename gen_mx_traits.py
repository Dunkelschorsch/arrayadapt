#!env python

import re

def c_to_mx_typename(c_type, special_map):
	m = re.search("([a-zA-Z0-9]+)_t", c_type)
	if m == None:
		mx_type = c_type
	else:
		mx_type = m.groups()[0]
	if c_type in special_map:
		mx_type = special_map[c_type]
	return mx_type.upper()

c_type = ('void', 'bool', 'double', 'float', 'uint64_t', 'int64_t', 'uint32_t', 'int32_t', 'uint16_t', 'int16_t', 'uint8_t', 'int8_t')
special_map = {'float': 'single', 'bool': 'logical' }

empty_trait = "template <class T>\nstruct mx_traits { };\n\n"
header_guard = """#ifndef HAVE_MX_TRAITS_HPP
#define HAVE_MX_TRAITS_HPP

#include <mex.h>

"""

trait_template = """// %s
template<> struct mx_traits<%s> {
  static const mxClassID classId = mx%s_CLASS;

  static inline const char* name() {
    return "%s";
  }
};

"""

mx_traits_header = open('include/mx_traits.hpp', 'wt')

mx_traits_header.write(header_guard)
mx_traits_header.write(empty_trait)

for type_curr in c_type:
	for constness in ("", "const ",):
		full_type = constness + type_curr
		mx_traits_header.write(trait_template % (full_type, full_type, c_to_mx_typename(type_curr, special_map), full_type))

mx_traits_header.write("#endif  // HAVE_MX_TRAITS_HPP\n")

mx_traits_header.close()

