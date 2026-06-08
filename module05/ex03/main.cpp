#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    Intern RandomIntern;

    std::cout << "\n--- Testing valid forms ---\n";

    AForm *f1 = RandomIntern.makeForm("robotomy request", "Bender");
    AForm *f2 = RandomIntern.makeForm("presidential pardon", "Youssef");
    AForm *f3 = RandomIntern.makeForm("shrubbery creation", "Garden");

    std::cout << "\n--- Testing invalid form ---\n";

    AForm *invalid = RandomIntern.makeForm("unknown form", "Nobody");

    delete f1;
    delete f2;
    delete f3;
    delete invalid;


    return 0;
}
