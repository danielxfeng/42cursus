#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    std::cout << &str << ", " << stringPTR << ", " << &stringREF << std::endl;
    std::cout << str << ", " << *stringPTR << ", " << stringREF << std::endl;
}