# pragma once

# ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"

class HumanA {
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack(void);
    
    private:
        std::string name_;
        Weapon *weapon_;
};

# endif // HUMAN_A_H