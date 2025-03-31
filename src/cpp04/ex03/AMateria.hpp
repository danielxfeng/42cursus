#pragma once 

#include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria {
    public:
        AMateria(void);
        AMateria(const AMateria &o);
        AMateria &operator=(const AMateria &o);
        virtual ~AMateria(void);

        AMateria(std::string const & type);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
    
    protected:
        std::string type_;
};
