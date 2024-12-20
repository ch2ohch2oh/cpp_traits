#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template <typename T>
struct Calculator
{
    T add(const T a, const T b)
    {
        return a + b;
    }

    T div(const T a, const T b)
    {
        return a / b;
    }
};

void partial_usage()
{
    string a{"123"};
    string b{"456"};
    // This is allowed even if we cannot divide two strings,
    // as long as we do not call `div`.
    Calculator<string> c;
    c.add(a, b);
    // c.div(a, b); COMPILE ERROR
}

void argument_deduction()
{
    // C++17 class template argument deduction
    vector ints{1, 2, 3}; // Deduced as vector<int>
}

int main(int argc, char const *argv[])
{
    partial_usage();

    std::cout << "done" << std::endl;
    return 0;
}
