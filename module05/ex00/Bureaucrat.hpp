#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string new_name, int new_grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);       
    Bureaucrat& operator=(const Bureaucrat& other);

    std::string getName() const;
    int getGrade() const;

    class GradeTooHighException : public std::exception 
    {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception 
    {
    public:
        const char* what() const throw();
    };
    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br);
#endif