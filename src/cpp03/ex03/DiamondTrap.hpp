# pragma once
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &o);
        DiamondTrap &operator=(const DiamondTrap &o);
        ~DiamondTrap();

        DiamondTrap(std::string name);
        
        void attack(const std::string& target);
        void whoAmI();

    private:
        std::string name_;
};
