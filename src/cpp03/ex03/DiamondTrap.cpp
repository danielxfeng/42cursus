# include "DiamondTrap.hpp"
# include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor" << std::endl;
    hit_points_ = FragTrap::hit_points_;
    energy_points_ = ScavTrap::energy_points_;
    attack_damage_ = FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap &o) : ClapTrap(o), ScavTrap(o), FragTrap(o), name_(o.name_) {
    std::cout << "DiamondTrap copy constructor for " << name_ << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &o) {
    name_ = o.name_;
    hit_points_ = o.hit_points_;
    energy_points_ = o.energy_points_;
    attack_damage_ = o.attack_damage_;
    std::cout << "DiamondTrap copy assignment operator" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor for " << name_ << std::endl; }

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name) {
    std::cout << "DiamondTrap name constructor for " << name_ << std::endl;
    hit_points_ = FragTrap::hit_points_;
    energy_points_ = ScavTrap::energy_points_;
    attack_damage_ = FragTrap::attack_damage_;
}

void DiamondTrap::attack(const std::string& target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI() {
    std::cout << "I am " << name_ << " and my ClapTrap name is " << ClapTrap::name_ << std::endl;
}
