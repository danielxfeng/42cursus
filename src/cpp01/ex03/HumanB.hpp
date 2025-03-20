# pragma once

# ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack(void);
    
    private:
        std::string name_;
        Weapon *weapon_;
};

# endif // HUMAN_B_H