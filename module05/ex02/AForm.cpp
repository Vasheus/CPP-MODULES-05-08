#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150){}

AForm::AForm(std::string new_name, int signGrade, int execGrade)
    : name(new_name), isSigned(false), gradeToSign(signGrade), gradeToExecute(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute){}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() 
{
        std::cout << "AForm: " << name << " destroyed." << std::endl;

}

std::string AForm::getName() const 
{
    return this->name;
}

bool AForm::getIsSigned() const 
{
    return this->isSigned;
}

int AForm::getGradeToSign() const 
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const 
{
    return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b) 
{
    if (b.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return "AForm: Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() 
{
    return "AForm: Cannot execute because the form is not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "Form name: " << f.getName() << "\n"
        << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << "\n"
        << "Grade required to sign: " << f.getGradeToSign() << "\n"
        << "Grade required to execute: " << f.getGradeToExecute();
    return out;
}
