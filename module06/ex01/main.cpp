#include <iostream>
#include "Serializer.hpp"

int main()
{
    std::cout << "----- Test-----" << std::endl;

    Data data;
    data.id = 98756;
    data.name = "Object";

    std::cout << "Original Data address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << " Pointers match!" << std::endl;
    else
        std::cout << " Pointers do not match!" << std::endl;

    std::cout << "Deserialized Data content -> id: " << ptr->id
              << ", name: " << ptr->name << std::endl;
}
