#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "Bureaucrat: " << name << " destroyed." << std::endl;
}

std::string Bureaucrat::getName() const 
{ 
    return this->name; 
}
int Bureaucrat::getGrade() const 
{ 
    return this->grade; 
}

void Bureaucrat::incrementGrade() 
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() 
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm &form) 
{
    try 
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } 
    catch (std::exception &excep) 
    {
        std::cout << name << " couldn’t sign " << form.getName()
                  << " because " << excep.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const 
{
    try 
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    } 
    catch (std::exception &excep) 
    {
        std::cout << name << " couldn’t execute " << form.getName()
                  << " because " << excep.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Bureaucrat: Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Bureaucrat: Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) 
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
