# pragma once
# include <string>

class Animal {

    public:
        Animal(void);
        Animal(const Animal &o);
        Animal &operator=(const Animal &o);
        virtual ~Animal(void);

        virtual void makeSound(void) const = 0;
        virtual const std::string &getType(void) const;

    protected:
        std::string type_;
};
