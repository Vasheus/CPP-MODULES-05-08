#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(std::string new_name, int signGrade, int execGrade)
    : name(new_name), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() 
{
    std::cout << "Form " << name << " destroyed." << std::endl;
}



std::string Form::getName() const 
{
     return name; 
}
bool Form::getIsSigned() const 
{
     return isSigned; 
}
int Form::getGradeToSign() const 
{
     return gradeToSign; 
}
int Form::getGradeToExecute() const 
{ 
    return gradeToExecute; 
}



const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form grade is too low!";
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << "Form " << f.getName()
        << " [Sign grade: " << f.getGradeToSign()
        << ", Execute grade: " << f.getGradeToExecute()
        << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") << "]";
    return out;
}
