# pragma once
# include <string>

class WrongAnimal {
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &o);
        WrongAnimal &operator=(const WrongAnimal &o);
        ~WrongAnimal(void);

        void makeSound(void) const;

        std::string getType(void) const;
    
    protected:
        std::string type_;
};
