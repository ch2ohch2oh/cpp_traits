#include <iostream>
#include <cassert>

using namespace std;

// Since C++14: return type deduction
template <typename T1, typename T2>
auto max(T1 x, T2 y)
{
    return x > y ? x : y;
}

float max(float x, float y)
{
    cout << "float max(float, float)" << endl;
    return x > y ? x : y;
}

int main(int argc, char const *argv[])
{
    assert(2.3 == max(2.3, 1));

    // <> indicates to use the template version only
    ::max<>(1, 2);

    std::cout << "done" << std::endl;
    return 0;
}
