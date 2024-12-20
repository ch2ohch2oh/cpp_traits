#include <iostream>
#include <type_traits>

template <typename T>
struct TypeIdentity
{
    // By convention, the returned type is called `type`.
    using type = T;
};

// Typename dance
template <typename T>
using TypeIdentity_t = typename TypeIdentity<T>::type;

static_assert(std::is_same_v<int, TypeIdentity_t<int>>);

// std::integral_constant
// std::bool_constant

static_assert(true == std::integral_constant<bool, true>::value);
static_assert(true == std::bool_constant<true>::value);

static_assert(true == std::integral_constant<bool, true>{}());

int main(int argc, char const *argv[])
{
    std::cout << "done" << std::endl;
    return 0;
}
