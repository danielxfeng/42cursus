#pragma once

#include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &o);
        ClapTrap &operator=(const ClapTrap &o);
        ~ClapTrap();

        ClapTrap(std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string name_;
        unsigned int hit_points_{10};
        unsigned int energy_points_ {10};
        unsigned int attack_damage_{0};
};