#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{

    Bureaucrat alice("Alice", 1); 
    Bureaucrat bob("Bob", 70);      
    Bureaucrat charlie("Charlie", 150); 

    ShrubberyCreationForm tree("olive");
    RobotomyRequestForm robot("atom-301");
    PresidentialPardonForm pardon("Pre");

    std::cout << "\n=== Form===\n";
    std::cout << tree << "\n\n" << robot << "\n\n" << pardon << "\n\n";

    std::cout << "\n===Sign===\n";
    charlie.signForm(tree); 
    bob.signForm(tree);     
    alice.signForm(robot);    
    alice.signForm(pardon);  

    std::cout << "\n=== Executing Forms ===\n";
    charlie.executeForm(tree); 
    bob.executeForm(tree);     
    bob.executeForm(robot);

    alice.executeForm(robot);   
    alice.executeForm(pardon);

    std::cout << "\n===Done===\n";

    return 0;
}
