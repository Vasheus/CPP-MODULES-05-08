#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::vector<int>::iterator it;
        it = easyfind(v, 20);
        std::cout << "Found value: " << *it << std::endl;

        it = easyfind(v, 10);
        std::cout << "Found value: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    std::list<int> lst;
    
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    lst.push_back(400);
    lst.push_back(500);

    
    try
    {
        std::list<int>::iterator iter;
        iter = easyfind(lst, 200);
        std::cout << "lst value at iter: " << *iter << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "excetion caught " << e.what() << std::endl;
    }

    
    return 0;
}
