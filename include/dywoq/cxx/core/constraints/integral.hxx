/*
 * dywoq 2025
 *
 * Licensed under Apache License 2.0:
 * https://github.com/dywoq/cxx/blob/main/LICENSE
 *
 * Repository:
 * https://github.com/dywoq/cxx
 */

#ifndef _DYWOQ_CXX_CORE_CONSTRAINTS_INTEGRAL_HXX
#define _DYWOQ_CXX_CORE_CONSTRAINTS_INTEGRAL_HXX

#include "../../__config.hxx"
#include "satisfied.hxx"

#if _DYWOQ_CXX__VERSION_SUPPORTED
namespace dywoq::cxx::core::constraints {
  template <typename _Tp> struct is_signed_integral : satisfied<_Tp, false> {};
  template <> struct is_signed_integral<signed char> : satisfied<signed int, true> {};
  template <> struct is_signed_integral<signed short> : satisfied<signed short, true> {};
  template <> struct is_signed_integral<signed int> : satisfied<signed int, true> {};
  template <> struct is_signed_integral<signed long long> : satisfied<signed int, true> {};
  template <typename _Tp> inline constexpr auto is_signed_v = is_signed_integral<_Tp>::yes;

  template <typename _Tp> struct is_unsigned_integral : satisfied<_Tp, false> {};
  template <> struct is_unsigned_integral<unsigned char> : satisfied<unsigned int, true> {};
  template <> struct is_unsigned_integral<unsigned short> : satisfied<unsigned short, true> {};
  template <> struct is_unsigned_integral<unsigned int> : satisfied<unsigned int, true> {};
  template <> struct is_unsigned_integral<unsigned long long> : satisfied<unsigned int, true> {};
  template <typename _Tp> inline constexpr auto is_unsigned_integral_v = is_unsigned_integral<_Tp>::yes;

  template <typename _Tp> struct is_integral : satisfied<_Tp, is_signed_v<_Tp> || is_unsigned_integral_v<_Tp>> {};
  template <typename _Tp> inline constexpr auto is_integral_v = is_integral<_Tp>::yes;
} // namespace dywoq::cxx::core::constraints
#endif

#endif
