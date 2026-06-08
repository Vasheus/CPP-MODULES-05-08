#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    try
    {
        Bureaucrat high("highest", 1);
        Bureaucrat mid("middle", 50);
        Bureaucrat low("lowest", 150);

        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;

        std::cout << "======FORUMS=======\n" << std::endl;

        Form formA("A", 150, 30);
        Form formB("B", 150, 10);
        Form formC("C", 1, 10);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;
        std::cout << "======SIGN=======\n" << std::endl;

        high.signForm(formA);
        high.signForm(formB);
        high.signForm(formC);
        std::cout << "=============" << std::endl;
        mid.signForm(formA);
        mid.signForm(formB);
        mid.signForm(formC);
        std::cout << "=============" << std::endl;
        low.signForm(formA);
        low.signForm(formB);
        low.signForm(formC);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception for to be caught: " << e.what() << std::endl; 
    }


    std::cout << "\n===invalid Forms===" << std::endl;

    try 
    {
        Form invalidHigh("Invalid High", 0, 10);
    } 
    catch (std::exception &excep) 
    {
         std::cerr << "Caught exception: " << excep.what() << std::endl;
    }

    try 
    {
        Form invalidLow("Invalid Low", 151, 100);
    } 
    catch (std::exception &excep) 
    {
        std::cerr << "Caught exception: " << excep.what() << std::endl;
    }

    return 0;
}

