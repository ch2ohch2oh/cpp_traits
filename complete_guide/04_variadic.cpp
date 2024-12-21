#include <iostream>
#include <cassert>
#include <vector>

// Must put this before the templated verison
void print() {}

template <typename T, typename... Types>
void print(T x, Types... rest)
{
    std::cout << x << std::endl;
    print(rest...);
}

// Fold expression (since C++17)
template <typename... Types>
void print2(Types... args)
{
    (std::cout << ... << args) << std::endl;
}

int main(int argc, char const *argv[])
{
    print(1, 2.3, "4");

    print2(1, 2.3, "4");

    std::cout << "done" << std::endl;
    return 0;
}
