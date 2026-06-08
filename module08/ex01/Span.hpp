#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

class Span
{

    public:
        std::vector<int> container;
        unsigned int     maxSize;
        Span();
        Span(unsigned int N);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(int nm);

        template<typename It>
        void addRange(It begin, It end)
        {
            while (begin != end)
            {
                addNumber(rand());
                ++begin;
            }
        }

        unsigned int shortestSpan();
        unsigned int longestSpan();
        void printContent();

        
};


#endif