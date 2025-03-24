#include <iostream>
#include <sstream>

template <typename... Args>
std::string stringJoin(const std::string &separator, const Args &...args)
{
    if (sizeof...(args) == 0)
        return "";

    std::ostringstream ss;
    ((ss << args << separator), ...);

    std::string joinedString = ss.str();
    joinedString.erase(joinedString.size() - separator.size());
    return joinedString;
}

int main()
{
    std::cout << stringJoin(", ", 1, 3.14, "hello world") << '\n';
    return 0;
}
