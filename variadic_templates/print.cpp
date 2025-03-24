#include <iostream>

template <typename... Args>
void print(std::ostream &ostream, const Args &...args)
{
    ((ostream << args << '\n'), ...);
}

template <typename... Args>
void print(const Args &...args)
{
    print(std::cout, args...);
}

int main(int argc, char **argv)
{
    print(1, 1.2, 12ul, "Hello, World!");
    print(std::cerr, "error-message-1", "error-message-2", 123ll, 456ul);

    return 0;
}