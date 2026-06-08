#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span &src)
{
    *this = src;
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->maxSize = src.maxSize;
        this->container = src.container;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (container.size() >= maxSize)
        throw std::out_of_range("container already full");
    container.push_back(n);
}

unsigned int Span::shortestSpan()
{
    if (container.size() < 2)
        throw std::out_of_range("container only has 1 element");

    std::vector<int> tmp = container;
    std::sort(tmp.begin(), tmp.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < tmp.size(); i++)
    {
        unsigned int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan()
{
    if (container.size() < 2)
        throw std::out_of_range("container only has 1 element");

    int minVal = *std::min_element(container.begin(), container.end());
    int maxVal = *std::max_element(container.begin(), container.end());

    return maxVal - minVal;
}

void Span::printContent() 
{
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << std::endl;
}
