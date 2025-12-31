/*
 * dywoq 2025
 *
 * Licensed under Apache License 2.0:
 * https://github.com/dywoq/cxx/blob/main/LICENSE
 *
 * Repository:
 * https://github.com/dywoq/cxx
 */

#ifndef _DYWOQ_CXX_CORE_CONSTRAINTS_SATISFIED_HXX
#define _DYWOQ_CXX_CORE_CONSTRAINTS_SATISFIED_HXX

#include "../../__config.hxx"

#if _DYWOQ_CXX__VERSION_SUPPORTED
namespace dywoq::cxx::core::constraints {
  /**
   * Represents the base class of all constraints,
   * indicating whether constraint satisfied or not.
   *
   * Move and copy semantics are forbidden and deleted explicitly.
   */
  template <typename _Tp, bool _Satisfied> struct satisfied {
    using type = _Tp;
    inline static constexpr bool yes = _Satisfied;
    satisfied(satisfied &) = delete;
    satisfied(satisfied &&) = delete;
    satisfied(const satisfied &) = delete;
    satisfied(const satisfied &&) = delete;
  };
} // namespace dywoq::cxx::core::constraints
#endif

#endif
