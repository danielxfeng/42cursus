#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

std::string truncate(std::string str) {
	return str.length() > 10 ? str.substr(0, 9) + "." : str;
}

void PhoneBook::updateCount()
{
    next_ = next_ == CAPACITY - 1 ? 0 : next_ + 1;
    if (size_ < CAPACITY)
        ++size_;
}

void PhoneBook::add(std::string first_name, std::string last_name, std::string nick_name,
    std::string phone_number, std::string darkest_secret) {
    contacts_[next_].set(first_name, last_name, nick_name, phone_number, darkest_secret);
    updateCount();
}

void PhoneBook::query(size_t idx)
{
    if (idx >= size_)
        return;
    Contact &c = contacts_[idx];
    std::cout << "Firstname: " << c.getFirstName() << std::endl;
    std::cout << "Lastname: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}

void PhoneBook::queryAll()
{
    std::cout << "|" << std::setw(10) << "Index"
    << "|" << std::setw(10) << "Firstname"
    << "|" << std::setw(10) << "Lastname"
    << "|" << std::setw(10) << "Nickname"
    << "|" << std::endl;
    for (size_t idx = 0; idx < size_; ++idx) {
        std::cout << "|" << std::setw(10) << idx
        << "|" << std::setw(10) << truncate(contacts_[idx].getFirstName())
        << "|" << std::setw(10) << truncate(contacts_[idx].getLastName())
        << "|" << std::setw(10) << truncate(contacts_[idx].getNickName())
        << "|" << std::endl;
    }
}
