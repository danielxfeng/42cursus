#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
    public:
        FragTrap();
        FragTrap(const FragTrap &o);
        FragTrap &operator=(const FragTrap &o);
        ~FragTrap();

        FragTrap(std::string name);
        void highFivesGuys();
};
