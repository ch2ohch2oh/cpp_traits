#include <iostream>
#include <cassert>
#include <vector>

template <int n>
int add(int x)
{
    return x + n;
}

// CANNOT use float as nontype template parameter!
// template <float n>
// float add_f(float x)
// {
//     return x + n;
// }

int main(int argc, char const *argv[])
{
    std::cout << "add<3>(4) = " << add<3>(4) << std::endl;

    std::cout << "done" << std::endl;
    return 0;
}
