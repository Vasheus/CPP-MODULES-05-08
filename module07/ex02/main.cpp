#include <iostream>
#include "Array.hpp"

int main()
{

    int *p = new int;
    std::cout << *p << std::endl;

    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 10;

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;


    const Array<int>& ca = a;
    std::cout << "ca: ";
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << ca[i] << " ";
    std::cout << std::endl;


    std::cout << "=======================Test Copy===================" << std::endl;
    Array<int> b(a);
    b[0] = 999;

    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

    std::cout << "=======================Test Assignement===================" << std::endl;
    Array<int> c;
    c = a;

    c[0] = 7777;
    std::cout << "c: ";
    for (unsigned int i = 0; i < c.size(); ++i)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "======================Invalid===================" << std::endl;
    try 
    {
        std::cout << a[100] << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception thrown: " << e.what() << std::endl;
    }

    return 0;
}
