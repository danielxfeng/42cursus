#include "PhoneBook.hpp"
#include <iostream>

std::string getInputString(std::string prompt) {
    std::string var = "";
    while (!std::cin.eof() && var.empty()) {
        std::cout << "Please input the " << prompt << ":" << std::endl;
        std::getline(std::cin, var);
    }
    return var;
}

void handleAdd(PhoneBook &pb)
{
    auto firstname = getInputString("Firstname");
    auto lastname = getInputString("Lastname");
    auto nickname = getInputString("Nickname"); 
    auto pn = getInputString("Phone Number"); 
    auto ds = getInputString("Darkest Secret");
    pb.add(firstname, lastname, nickname, pn, ds);
}

void handleQuery(PhoneBook &pb)
{
    pb.queryAll();
    std::string idxString = "";
    while (!std::cin.eof() && idxString != "EXIT") {
        std::cout << "Please input a valid index:" << std::endl;
        std::getline(std::cin, idxString);
        if (idxString.length() != 1 || idxString.at(0) < '0' || idxString.at(0) > '7')
            continue;
        size_t idx = std::stoi(idxString);
            pb.query(idx);
    }
}

int main(void)
{
    auto pb = PhoneBook();
    std::string cmd = "";
    while (!std::cin.eof() && cmd!= "EXIT")
    {
        std::cout << "Please input the command:" << std::endl;
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            handleAdd(pb);
        else if (cmd == "SEARCH")
            handleQuery(pb);
        else
            continue;
    }
    return EXIT_SUCCESS;
}
