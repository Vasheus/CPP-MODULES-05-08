#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> 
#include <algorithm>
#include <cstddef>

template <typename T>
class Array
{
    private:
        T*              dataref;
        unsigned int    sizeref;

    public:
        Array() : dataref(NULL), sizeref(0) {}

        Array(unsigned int n) : dataref(NULL), sizeref(n)
        {
            if (n == 0)
            {
                dataref = NULL;
                return;
            }
            dataref = new T[n]();
        }

        Array(const Array& other) : dataref(NULL), sizeref(other.sizeref)
        {
            if (sizeref == 0)
            {
                dataref = NULL;
                return;
            }
            dataref = new T[sizeref]();
            for (unsigned int i = 0; i < sizeref; ++i)
                dataref[i] = other.dataref[i];
        }

        ~Array()
        {
            delete[] dataref;
        }
        Array& operator=(const Array& other)
        {
            if (this == &other)
                return *this;
            delete[] dataref;
            sizeref = other.sizeref;

            if (sizeref == 0)
            {
                dataref = NULL;
                return *this;
            }
            dataref = new T[sizeref];
            for (unsigned int i = 0; i < sizeref; ++i)
                dataref[i] = other.dataref[i];

            return *this;
}

        T& operator[](unsigned int index)
        {
            if (index >= sizeref)
                throw std::out_of_range("Array index out of range");
            return dataref[index];
        }
        const T& operator[](unsigned int index)const
        {
            if (index >= sizeref)
                throw std::out_of_range("Array index out of range");
            return dataref[index];
        }

        unsigned int size() const { return sizeref; }
};

#endif
