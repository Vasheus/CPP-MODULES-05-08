#include <iostream>
#include <string>
#include <cctype>

#include "iter.hpp"

template<typename U>

void print(U    &x)
{
    std::cout << x << std::endl;
}

void increment(int &n)
{
    ++n;
}

void addstr(std::string &s)
{
    s += "!!!!!!!!!";
}

void toUpperChar(char &c)
{
    c = static_cast<char>(std::toupper(c));
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::size_t nlen = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "ints:" << std::endl;
    iter(numbers, nlen, print<int>);
    iter(numbers, nlen, increment);
    std::cout << "After increment:" << std::endl;
    iter(numbers, nlen, print<int>);

    std::cout << "----------------------" << std::endl;

    std::string words[] = {"hello", "world", "iter"};
    std::size_t wlen = sizeof(words) / sizeof(words[0]);

    std::cout << "strings:" << std::endl;
    iter(words, wlen, print<std::string>);

    iter(words, wlen, addstr);
    std::cout << "After addstr:" << std::endl;
    iter(words, wlen, print<std::string>);

    std::cout << "----------------------" << std::endl;

    char letters[] = {'a','b','c','D'};
    std::size_t llen = sizeof(letters) / sizeof(letters[0]);

    std::cout << "chars before:" << std::endl;
    iter(letters, llen, print<char>);
    iter(letters, llen, toUpperChar);
    std::cout << "chars after toupper:" << std::endl;
    iter(letters, llen, print<char>);

    return 0;
}
