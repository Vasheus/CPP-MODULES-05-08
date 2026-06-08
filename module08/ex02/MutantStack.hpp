#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        typedef std::stack<T>                             stack;
        typedef typename stack::container_type            container;
        typedef typename container::iterator               iterator;

        MutantStack() : stack()
        {
            std::cout << "Default Constructor called" << std::endl;
        }

        MutantStack(const MutantStack &other) : stack(other)
        {
            std::cout << "Copy Constructor called" << std::endl;
        }

        ~MutantStack()
        {
            std::cout << "Destructor called" << std::endl;
        }

        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
                stack::operator=(other);
            return *this;
        }

        iterator begin() { return this->c.begin(); }
        iterator end()   { return this->c.end(); }
};

#endif
