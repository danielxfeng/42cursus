#pragma once

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &o);
        ScavTrap &operator=(const ScavTrap &o);
        ~ScavTrap();

        ScavTrap(std::string name);
        void attack(const std::string &target);
        void guardGate();
};