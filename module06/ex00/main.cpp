#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) 
{
    (void)ac;
    if(ac != 2)
        return 1;

    ScalarConverter::convert(av[1]);    
    return 0;
}
