#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm: " << target << " destroyed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->target = other.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "[***drilling noises***]" << std::endl;

    static int random = 0;
    random = 1 - random;

    if (random == 1)
        std::cout << target 
                  << " has been robotomized successfully!" 
                  << std::endl;
    else
       std::cout << target 
                  << " failed to be robotomized!!" 
                  << std::endl;;
}
