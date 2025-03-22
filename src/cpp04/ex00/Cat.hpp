#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat(void);
        Cat(const Cat &o);
        Cat &operator=(const Cat &o);
        ~Cat(void);

        void makeSound(void) const;
};
