# pragma once

# include "AMateria.hpp"
# include <string>

class ICharacter
{
    public:
        ICharacter();
        ICharacter(const ICharacter &o);
        ICharacter &operator=(const ICharacter &o);
        virtual ~ICharacter();
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};
