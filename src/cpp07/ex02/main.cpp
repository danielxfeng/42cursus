# include "Array.hpp"
# include <iostream>


int main()
{
    auto arr = Array<int>();
    std::cout << arr.size() << std::endl;
    try {
        arr[1];
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    arr = Array<int>(5);
    std::cout << arr.size() << std::endl;
    std::cout << arr[3] << std::endl;
}

