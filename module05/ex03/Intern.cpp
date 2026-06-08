#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "default constructor called for Intern" << std::endl;
}
Intern::Intern(const Intern& other)
{
    (void)other;
}
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
Intern::~Intern()
{
    std::cout << "deconstructor called for Intern" << std::endl;
}

AForm *makeRobot(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *makePrPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
    std::string requests[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    AForm* (*functions[3])(std::string) = {makeRobot, makePrPardon, makeShrubbery};

    for (int i = 0; i < 3; i++)
    {
        if(name == requests[i])
        {
            std::cout << "Intern creates form: " << name << std::endl;
            return functions[i](target);
        }
    }
    std::cout << "[[[REQUEST]]]\n" << std::endl;  
    return NULL;
}