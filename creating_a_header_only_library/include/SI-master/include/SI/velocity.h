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

#include "detail/operator_helpers.h"

#include "detail/number_parser.h"
#include "detail/unit.h"
#include "length.h"
#include "time.h"

namespace SI {

/// Type for velocity where v = L / T
template <typename _type, typename _ratio>
using velocity_t = detail::unit_t<'v', 1, _type, _ratio>;

namespace detail {
BUILD_UNIT_FROM_DIVISON(velocity_t, length_t, time_t)
}

} // namespace SI