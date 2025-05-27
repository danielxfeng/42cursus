#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>

Base *generate(void)
{

    const int r = std::rand() % 3;
    switch (r)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        throw std::runtime_error("What did you do?");
    }
}

void identify(Base *p)
{
    if (p == nullptr)
        std::cout << "pointer null" << std::endl;
    else if (dynamic_cast<A *>(p))
        std::cout << "pointer a" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "pointer b" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "pointer c" << std::endl;
    else
        throw std::runtime_error("What did you do?");
}

void identify(Base &p)
{
    try
    {
        auto a = dynamic_cast<A &>(p);
        std::cout << &a << std::endl;
    }
    catch (std::bad_cast &e)
    {
    };
    try
    {
        auto b = dynamic_cast<B &>(p);
        std::cout << &b << std::endl;
    }
    catch (std::bad_cast &e)
    {
    };
    try
    {
        auto c = dynamic_cast<C &>(p);
        std::cout << &c << std::endl;
    }
    catch (std::bad_cast &e)
    {
    };
}

int main()
{
    for (size_t i = 0; i < 50; ++i)
    {
        Base *b = generate();
        if (i % 2)
            identify(b);
        else
            identify(*b);
    }
}