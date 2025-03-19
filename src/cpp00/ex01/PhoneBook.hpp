#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

#define CAPACITY 8

class PhoneBook {
    public:
        void add(std::string first_name, std::string last_name, std::string nick_name,
            std::string phone_number, std::string darkest_secret);
        void query(size_t idx);
        void queryAll();

    private:
        size_t next_{0};
        size_t size_{0};
        
        void updateCount();
        Contact contacts_[CAPACITY];
};

#endif // PHONEBOOK_H
