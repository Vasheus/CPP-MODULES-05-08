#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form();
    Form(std::string new_name, int signGrade, int execGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    class GradeTooHighException : public std::exception 
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception 
    {
        const char* what() const throw();
    };

    void beSigned(const Bureaucrat &b);
};
std::ostream &operator<<(std::ostream &out, const Form &f);


#endif
