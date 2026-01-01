## Synopsis

```c++
namespace dywoq::cxx::core::type_traits {
  template <typename T, bool Satisfied> struct satisfied;
  
  template <typename T, typename U> struct is_same;
  template <typename T, typename U> inline constexpr auto is_same_v;
}
```

## Symbols
### `satisfied`
- _Declaration_: 
```c++
  template <typename T, bool Satisfied> struct satisfied {
    using type = T;
    inline static constexpr auto yes = Satisfied;

    satisfied(const satisfied &) = delete;
    satisfied(satisfied &&) = delete;
  };
```
- _Description_: A compile-time base class for type traits, which provides single yes/no condition, telling whether type trait is satisfied or not.
### `is_same`
- _Declaration_:
```c++
template<typename T, typename U>
struct is_same : satisfied<T, false> {};
```
- _Description_: A type trait checking whether T and U are equal or not. If they are, `is_same<T, U>::yes` is true.

### `is_same_v`
- _Declaration_:
```c++
template <typename T, typename U> 
inline constexpr auto is_same_v = is_same<T, U>::yes;
```
- _Description_: Short way to use type trait `is_same<T, U>`.
