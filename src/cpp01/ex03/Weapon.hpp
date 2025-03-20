# pragma once

# ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
    public:
        Weapon();
        Weapon(std::string type);
        const std::string getType(void);
        void setType(std::string type);
    private:
        std::string type_;
};

# endif // WEAPON_H