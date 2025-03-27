# pragma once

# include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character(void);
        Character(std::string name);
        Character(const Character &o);
        Character &operator=(const Character &o);
        virtual ~Character(void);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        std::string name_;
        AMateria *inventory_[4];
};