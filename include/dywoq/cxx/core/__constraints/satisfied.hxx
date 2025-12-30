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

namespace dywoq::cxx::core::constraints
{
  template <bool _Satisfied> struct satisfied
  {
    inline static constexpr bool yes = _Satisfied;
    satisfied(satisfied &) = delete;
    satisfied(satisfied &&) = delete;
    satisfied(const satisfied &) = delete;
    satisfied(const satisfied &&) = delete;
  };
} // namespace dywoq::cxx::core::constraints

#endif
