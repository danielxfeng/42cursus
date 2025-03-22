# include "Harl.hpp"
# include <iostream>

void Harl::complain( std::string level ) {
    std::string keys[4] = {"debug", "info", "warning", "error"};
    int i = 0;
    while (i < 4 && keys[i] != level)
        ++i;
    if (i == 4)
        return;
    switch(i) {
        case 0: debug();
        case 1: info();
        case 2: warning();
        case 3: error();
        default: return;
    }
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
