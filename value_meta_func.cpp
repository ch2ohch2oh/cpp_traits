#include <iostream>

// An identity metafunction
template <int X>
struct IntIdentity
{
    // By convention, the return value of a metafunction is called `value`.
    static constexpr int value = X; 
};

static_assert(123 == IntIdentity<123>::value);


// A generic identity metafunction
template <typename T, T Value>
struct ValueIdentity {
    static constexpr T value = Value;
};

static_assert(233 == ValueIdentity<int, 233>::value);


// Sum
template<int X, int Y>
struct IntSum {
    static constexpr int value = X + Y;
};

static_assert(3 == IntSum<1, 2>::value);


// Sum with cpp17 auto
template<auto X, auto Y>
struct IntSum2 {
    static constexpr auto value = X + Y;
};

static_assert(3 == IntSum2<1, 2>::value);


// Same thing again with constexpr
template<typename X, typename Y>
constexpr auto sum3(X x, Y y) {
    return x + y;
}

static_assert(4 == sum3(1, 3));


int main(int argc, char const *argv[])
{
    std::cout << "done" << std::endl;
    return 0;
}
