#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

std::string truncate(std::string str) {
	return str.length() > 10 ? str.substr(0, 9) + "." : str;
}

void PhoneBook::updateCount()
{
    idx_ = idx_ == CAPACITY - 1 ? 0 : idx_ + 1;
    if (size_ < CAPACITY)
        ++size_;
}

bool PhoneBook::add(std::string first_name, std::string last_name, std::string nick_name,
    std::string phone_number, std::string darkest_secret) {
    if (first_name.empty() || last_name.empty() || nick_name.empty()
        || phone_number.empty() || darkest_secret.empty())
        return false;
    updateCount();
    contacts_[idx_].set(first_name, last_name, nick_name, phone_number, darkest_secret);
    return true;
}

bool PhoneBook::query(size_t idx)
{
    if (idx >= size_)
        return false;
    std::cout << "|" << idx
              << "|" << std::setw(10) << truncate(contacts_[idx].getFirstName())
              << "|" << std::setw(10) << truncate(contacts_[idx].getLastName())
              << "|" << std::setw(10) << truncate(contacts_[idx].getNickName())
              << "|" << std::endl;
    return (true);
}

void PhoneBook::queryAll()
{
    for (Contact& c : contacts_) {
        std::cout << "Firstname: " << c.getFirstName() << std::endl;
        std::cout << "Lastname: " << c.getLastName() << std::endl;
        std::cout << "Nickname: " << c.getNickName() << std::endl;
        std::cout << "PhoneNumber: " << c.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
    }
}
