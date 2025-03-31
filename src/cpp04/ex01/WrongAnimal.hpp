# pragma once
# include <string>

class WrongAnimal {
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &o);
        WrongAnimal &operator=(const WrongAnimal &o);
        virtual ~WrongAnimal(void);

        virtual void makeSound(void) const;

        std::string getType(void) const;
    
    protected:
        std::string type_;
};
