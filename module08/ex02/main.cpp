#include <iostream>
#include "MutantStack.hpp"


int main()
{
    std::cout << "===== MUTANTSTACK TEST =====" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "MutantStack content:" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "===== COPY TEST =====" << std::endl;
    MutantStack<int> copy(mstack);

    std::cout << "Copied stack content:" << std::endl;
    for (MutantStack<int>::iterator it2 = copy.begin(); it2 != copy.end(); it2++)
        std::cout << *it2 << std::endl;

    std::cout << "===== ASSIGNMENT TEST =====" << std::endl;
    MutantStack<int> assign;
    assign = mstack;

    std::cout << "Assigned stack content:" << std::endl;
    for (MutantStack<int>::iterator it3 = assign.begin(); it3 != assign.end(); it3++)
        std::cout << *it3 << std::endl;

    std::cout << "===== STRING TEST =====" << std::endl;
    MutantStack<std::string> strstack;
    strstack.push("Hello");
    strstack.push("World");
    strstack.push("Mutant");
    strstack.push("Stack");

    for (MutantStack<std::string>::iterator sit = strstack.begin(); sit != strstack.end(); sit++)
        std::cout << *sit << std::endl;

    return 0;
}
