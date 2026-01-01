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

#if _DYWOQ_CXX__VERSION_SUPPORTED
_DYWOQ_CXX__NAMESPACE_CORE_BEGIN_VERSION(v1)

namespace type_traits {
  template <typename _Tp, bool _Satisfied> struct satisfied {
    using type = _Tp;
    inline static constexpr auto yes = _Satisfied;

    satisfied(const satisfied &) = delete;
    satisfied(satisfied &&) = delete;
  };
} // namespace type_traits

_DYWOQ_CXX__NAMESPACE_CORE_END_VERSION
#endif

#endif
