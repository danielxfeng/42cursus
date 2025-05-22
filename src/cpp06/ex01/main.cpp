#include "Serializer.hpp"
#include <iostream>

int main()
{ 
    auto *data_ptr = new Data();
    uintptr_t ptr = Serializer::serialize(data_ptr);
    auto *data_ptr2 = Serializer::deserialize(ptr);
    std::cout << data_ptr2->getValue() << std::endl;
    delete data_ptr;

    exit(EXIT_SUCCESS);
}