#include <iostream>
#include <cassert>
#include <string>
#include <vector>

template <typename T>
struct AccumulationTraits;

template <>
struct AccumulationTraits<int>
{
    using AccT = long;          // Type trait
    static long const zero = 0; // Value trait
};

template <>
struct AccumulationTraits<float>
{
    using AccT = double;
    static constexpr double zero = 0.0;
};

template <typename T>
auto accumulate(const T *start, const T *end)
{
    using AccT = typename AccumulationTraits<T>::AccT; // This is called fixed trait (vs parameterized trait)
    AccT total{};
    while (start != end)
    {
        total += *start;
        start++;
    }
    return total;
}

// Element types

template <typename T>
struct ElementT;

template <typename T>
struct ElementT<std::vector<T>>
{
    using Type = T;
};

// Transformation traits: removing/adding reference/const

// Predicate traits

template <typename T1, typename T2>
struct IsSameT
{
    static constexpr bool value = false;
};

template <typename T>
struct IsSameT<T, T>
{
    static constexpr bool value = true;
};

// Result type traits

int main(int argc, char const *argv[])
{
    int nums[4] = {1, 2, 3, 4};
    std::cout << "total = " << accumulate(nums, nums + 4) << std::endl;

    std::cout << typeid(typename ElementT<std::vector<int>>::Type).name() << std::endl;
    std::cout << typeid(typename std::vector<std::string>::value_type).name() << std::endl;

    std::cout << "IsSameT<int, double>::value = " << IsSameT<int, double>::value << std::endl;
    std::cout << "IsSameT<int, int>::value = " << IsSameT<int, int>::value << std::endl;

    std::cout
        << "done" << std::endl;
    return 0;
}
