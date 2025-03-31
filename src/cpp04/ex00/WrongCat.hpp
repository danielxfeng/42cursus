#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat(void);
        WrongCat(const WrongCat &o);
        WrongCat &operator=(const WrongCat &o);
        ~WrongCat(void);

        void makeSound(void) const;
};