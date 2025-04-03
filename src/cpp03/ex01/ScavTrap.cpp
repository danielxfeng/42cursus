#include "ScavTrap.hpp"
#include <iostream>


ScavTrap::ScavTrap() : ClapTrap() { 
    std::cout << "ScavTrap default constructor" << std::endl;
    hit_points_ = 100;
    energy_points_ = 50;
    attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &o) {
    *this = o;
    std::cout << "ScavTrap copy constructor for " << name_ << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &o) {
    name_ = o.name_;
    hit_points_ = o.hit_points_;
    energy_points_ = o.energy_points_;
    attack_damage_ = o.attack_damage_;
    std::cout << "ScavTrap copy assignment operator" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor for " << name_ << std::endl; }

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap name constructor for " << name_ << std::endl;
    hit_points_ = 100;
    energy_points_ = 50;
    attack_damage_ = 20;
}

void ScavTrap::attack(const std::string &string) {
    if (hit_points_ == 0 || energy_points_ == 0) {
        std::cout << "ScavTrap " << name_ << " has no points and cannot attack" << std::endl;
        return;
    }
    --hit_points_;
    --energy_points_;
    std::cout << "ScavTrap " << name_ << " attacks " << string << " , causing " << attack_damage_ << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name_ << " entered in Gate keeper mode" << std::endl;
}