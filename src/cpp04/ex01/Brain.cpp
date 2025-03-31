# include "Brain.hpp"
# include <iostream>

Brain::Brain(void) {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &o) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = o;
}

Brain &Brain::operator=(const Brain &o) {
    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas_[i] = o.ideas_[i];
    }
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
}
