#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        AForm();
        AForm(std::string new_name, int signGrade, int execGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const &excepxcepxecutor) const = 0;

        class GradeTooHighException : public std::exception 
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception 
        {
            const char* what() const throw();
        };
        class FormNotSignedException : public std::exception 
        {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
