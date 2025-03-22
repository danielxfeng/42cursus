# include "FragTrap.hpp"
# include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor" << std::endl;
    hit_points_ = 100;
    energy_points_ = 100;
    attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap &o) {
    *this = o;
    std::cout << "FragTrap copy constructor for " << name_ << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &o) {
    name_ = o.name_;
    hit_points_ = o.hit_points_;
    energy_points_ = o.energy_points_;
    attack_damage_ = o.attack_damage_;
    std::cout << "FragTrap copy assignment operator" << std::endl;
    return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor for " << name_ << std::endl; }

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap name constructor for " << name_ << std::endl;
    hit_points_ = 100;
    energy_points_ = 100;
    attack_damage_ = 30;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name_ << " says high five guys!" << std::endl;
}