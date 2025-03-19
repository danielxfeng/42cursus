#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
  public:
    void set(std::string first_name, std::string last_name, std::string nick_name, 
          std::string phone_number, std::string darkest_secret);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkestSecret();

  private:
    std::string first_name_;
    std::string last_name_;
    std::string nick_name_;
    std::string phone_number_;
    std::string darkest_secret_;
};

#endif // CONTACT_HPP
