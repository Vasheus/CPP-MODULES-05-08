#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b;
        std::cout << "bureaucrat name: " << b.getName() << " has grade :" << b.getGrade() << std::endl;
        std::cout << "=========================" << std::endl;

        Bureaucrat b1("b1", 1);
        std::cout << "bureaucrat name: " << b1.getName() << " grade :" << b1.getGrade() << std::endl;
        std::cout << "=========================" << std::endl;

        Bureaucrat b2(b1);
        std::cout << "bureaucrat name : " << b2.getName() << " grade :" << b2.getGrade() << std::endl;
        std::cout << "=========================" << std::endl;;

        Bureaucrat b3;
        b3 = b2;
        std::cout << "bureaucrat name : " << b3.getName() << " grade :" << b3.getGrade() << std::endl;
        std::cout << "=========================" << std::endl;;
        
        try
        {
            b1.incrementGrade();
        }
        catch (std::exception &e)
        {
            std::cout << "exception caught after increment for [b1]: " << e.what() << std::endl;
        }


        try
        {
            b.decrementGrade();
        }
        catch (std::exception &e)
        {
            std::cout << "exception caught after decrement for [b]: " << e.what() << std::endl;
        }

        Bureaucrat b4("b4", 158);
        std::cout << "bureaucrat name : " << b4.getName() << " grade :" << b4.getGrade() << std::endl;
    }
    
    catch (std::exception &e)
    {
        std::cout << "execption : " << e.what() << std::endl;
    }
    return 0;
}