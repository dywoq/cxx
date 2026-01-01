#ifndef _DYWOQ_CXX___CONFIG_HXX
#define _DYWOQ_CXX___CONFIG_HXX

#ifdef __cplusplus
#if __cplusplus >= 202002L
#define _DYWOQ_CXX__VERSION_SUPPORTED 1
#else
#define _DYWOQ_CXX__VERSION_SUPPORTED 0
#endif
#else
#define _DYWOQ_CXX__VERSION_SUPPORTED 0
#endif

#define _DYWOQ_CXX__NAMESPACE_CORE_VERSION_BEGIN(version)                                                              \
  namespace dywoq::cxx::core {                                                                                         \
    inline namespace __##version {
#define _DYWOQ_CXX__NAMESPACE_CORE_VERSION_END                                                                         \
  }                                                                                                                    \
  }

#endif
