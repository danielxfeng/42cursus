# include "Harl.hpp"
# include <iostream>

void Harl::complain( std::string level ) {
    std::string keys[4] = {"debug", "info", "warning", "error"};
    void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4 && keys[i] != level)
        ++i;
    if (i == 4)
        return;
    (this->*funcs[i])();
}

void Harl::debug( void ){
    std::cout << "Debug" << std::endl;
}

void Harl::info( void ){
    std::cout << "Info" << std::endl;
}
void Harl::warning( void ){
    std::cout << "Warning" << std::endl;
}

void Harl::error( void ){
    std::cout << "Error" << std::endl;
}
