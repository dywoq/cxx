# Contribution

## Code standard

### Use ugly names with prefix `__`
To avoid colliding with user-defined symbols and mark it as internal part clearly, write internal parts identifiers with prefix `__`.

It relates to:
- Function parameters:
```c++
int add(int __a, int __b) {
	return __a + __b;
}
```
- Local variables:
```c++
int add(int __a, int __b) {
	int __res = __a + __b;
	return __res;
}
```
- Private members of classes. Notice that you add  `_` at the end of private class variables names:
```c++
#include <concepts>

template<std::integral CountT>
class counter {
private:
	CountT __count_ = 0;
	
	void __reset() noexcept {
		CountT = 0;
	}
	
public:
	counter() noexcept {}
	void add(CountT __num) noexcept {
		__count_ += __num;
		if (__count_ > 10) {
			__reset();
		}
	}
};
```
- Functions:
```c++
int __private_add(int __a, int __b) {
	return __a + __b;
}

int add(int __a, int __b) {
	return __private_add(__a, __b);
}
```
and etc.

Use `clang-tidy` to find warnings about not using of `__`.  
### License warning
When you write code for `dywoq/cxx`, put it in the start of the source or header file:
```c++
/*
 * dywoq 2026
 *
 * Licensed under Apache License 2.0:
 * https://github.com/dywoq/cxx/blob/main/LICENSE
 *
 * Repository:
 * https://github.com/dywoq/cxx
 */
```

### Use `clang-format`
To ensure your code aligns with the format of the code, use `clang-format` to format the code.

### Headers

#### Guard macros
Their format:
```
#ifndef _DYWOQ_CXX_<PART>_<MASTER_HEADER>_<SUB_HEADER>_HXX
#define _DYWOQ_CXX_<PART>_<MASTER_HEADER>_<SUB_HEADER>_HXX
```
- **`<PART>`** -  The part of the library header is in: `CORE`, `RUNTIME`, `LIB`.
- **`<MASTER_HEADER>`** - The name of the master header: `SYNC`.
- **`<SUB_HEADER>`** - The name of the sub-header: `ATOMIC`

#### Use namespace macros to start namespaces in headers
For example, to start namespace `core` with `v1` version in headers:
```c++
_DYWOQ_CXX__NAMESPACE_CORE_BEGIN_VERSION(v1)

// ...

_DYWOQ_CXX__NAMESPACE_CORE_END_VERSION
```
