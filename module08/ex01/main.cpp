#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Content:" << std::endl;
        sp.printContent();

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;

        std::cout << "out of range add" << std::endl;
        sp.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "=====RANGETEST=====" << std::endl;

    try
    {
        Span sp2(10000);

        std::vector<int> big;
        for (int i = 0; i < 10000; i++)
            big.push_back(i);

        for (std::vector<int>::iterator it = big.begin(); it != big.end(); it++)
            sp2.addNumber(*it);

        std::cout << "Added 10000 numbers to sp2." << std::endl;

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp2.longestSpan() << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
