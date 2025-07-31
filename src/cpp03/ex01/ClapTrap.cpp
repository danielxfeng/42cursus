#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) { std::cout << "ClapTrap default constructor" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap &o) {
    *this = o;
    std::cout << "ClapTrap copy constructor for " << name_ << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &o) {
    name_ = o.name_;
    hit_points_ = o.hit_points_;
    energy_points_ = o.energy_points_;
    attack_damage_ = o.attack_damage_;
    std::cout << "ClapTrap copy assignment operator" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap destructor for " << name_ << std::endl; }

ClapTrap::ClapTrap(std::string name) : name_(name) { std::cout << "ClapTrap name constrcutor for " << name_ << std::endl;}

void ClapTrap::attack(const std::string &string) {
    if (hit_points_ == 0 || energy_points_ == 0) {
        std::cout << "ClapTrap " << name_ << " has no points and cannot attack" << std::endl;
        return;
    }
    --energy_points_;
    std::cout << "ClapTrap " << name_ << " attacks " << string << " , causing " << attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    amount = amount > hit_points_ ? hit_points_ : amount;
    hit_points_ -= amount;
    std::cout << "ClapTrap " << name_ << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hit_points_ == 0 || energy_points_ == 0) {
        std::cout << "ClapTrap " << name_ << " has no points and cannot be repaired" << std::endl;
        return;
    }
    --energy_points_;
    hit_points_ += amount;
    std::cout << "ClapTrap " << name_ << " is repaired by " << amount << " points!" << std::endl;
}
