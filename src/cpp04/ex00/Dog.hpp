#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog(void);
        Dog(const Dog &o);
        Dog &operator=(const Dog &o);
        ~Dog(void);

        void makeSound(void) const;
};
