#include <iostream>

void tprintf(const char *format)
{
    std::cout << format;
}

template <typename Head, typename... Tail>
void tprintf(const char *format, const Head &head, const Tail &...tails)
{
    while (*format != '\0')
    {
        if (*format == '{' && *(format + 1) == '}')
        {
            std::cout << head;
            tprintf(format + 2, tails...);
            break;
        }
        std::cout << *(format++);
    }
}

int main()
{
    tprintf("{} world{} {}\n", "Hello", '!', 123);
}