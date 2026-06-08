#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib> 
#include <ctime>
#include <exception>

Base *generate(void)
{
    static bool flag;
    flag = false;
    if (!flag)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        flag = true;
    }

    int r;
    r = std::rand() % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "Null pointer\n";
        return;
    }

    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (std::exception& e) 
    {
        std::cout << e.what() << std::endl;

    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Unknown\n";
}
