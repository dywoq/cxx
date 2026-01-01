/*
 * dywoq 2026
 *
 * Licensed under Apache License 2.0:
 * https://github.com/dywoq/cxx/blob/main/LICENSE
 *
 * Repository:
 * https://github.com/dywoq/cxx
 */
#ifndef _DYWOQ_CXX_CORE_TYPE_TRAITS_SAME_HXX
#define _DYWOQ_CXX_CORE_TYPE_TRAITS_SAME_HXX

#include "../../__config.hxx"
#include "dywoq/cxx/core/type_traits/satisfied.hxx"

#if _DYWOQ_CXX__VERSION_SUPPORTED
_DYWOQ_CXX__NAMESPACE_CORE_BEGIN_VERSION(v1)

namespace type_traits {
  template <typename _Tp, typename _Ut> struct is_same : satisfied<_Tp, false> {};
  template <typename _Tp> struct is_same<_Tp, _Tp> : satisfied<_Tp, true> {};
  template <typename _Tp, typename _Ut> inline constexpr auto is_same_v = is_same<_Tp, _Ut>::yes;
} // namespace type_traits

_DYWOQ_CXX__NAMESPACE_CORE_END_VERSION
#endif

#endif
