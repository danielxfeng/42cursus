#include "Contact.hpp"

void Contact::set(std::string first_name, std::string last_name,
	std::string nick_name, std::string phone_number, std::string darkest_secret) {
	first_name_ = first_name;
	last_name_ = last_name;
	nick_name_ = nick_name;
	phone_number_ = phone_number;
	darkest_secret_ = darkest_secret;
}

std::string Contact::getFirstName() {
    return first_name_;
}

std::string Contact::getLastName() {
    return last_name_;
}

std::string Contact::getNickName() {
    return nick_name_;
}

std::string Contact::getPhoneNumber() {
    return phone_number_;
}

std::string Contact::getDarkestSecret() {
    return darkest_secret_;
}
