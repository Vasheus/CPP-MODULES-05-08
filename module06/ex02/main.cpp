#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Identify.hpp"


int main()
{
    std::cout << "---- Testing generate() ----\n";

    for (int i = 0; i < 3; i++)
    {
        Base *obj = generate();

        std::cout << "Object " << i << ": ";

        identify(obj);

        std::cout << "Ref  " << i << ": ";
        identify(*obj);

        std::cout << "-----------------------------\n";

        delete obj;
    }

    return 0;
}