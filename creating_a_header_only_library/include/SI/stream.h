/**
 * This file is part of "SI" version 1.4.0
 * A header only c++ library that provides type safety and user defined literals
 * for handling pyhsical values defined in the International System of
 * Units
 *
 * https://github.com/bernedom/SI
 *
 * SPDX-License-Identifier: MIT
 *
 **/
#pragma once
#include "detail/string.h"
#include "detail/unit.h"

#include <istream>
#include <ostream>

template <char _symbol, char _exponent, typename _type, typename _ratio>
std::ostream &
operator<<(std::ostream &stream,
           const SI::detail::unit_t<_symbol, _exponent, _type, _ratio> &unit) {
  stream << unit.raw_value()
         << SI::unit_symbol<_symbol, _ratio, _exponent>::str;
  return stream;
}

template <char _symbol, char _exponent, typename _type, typename _ratio>
std::istream &
operator>>(std::istream &stream,
           SI::detail::unit_t<_symbol, _exponent, _type, _ratio> &obj) {
  _type v;
  std::string unit_symbol;
  stream >> v >> unit_symbol;

  if (unit_symbol.compare(SI::unit_symbol<_symbol, _ratio, _exponent>::str) !=
      0) {
    stream.setstate(std::ios::failbit);
  }
  obj.set_raw_value(v);
  return stream;
}
