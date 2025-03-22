# pragma once

# include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice(void);
        Ice(const Ice &o);
        Ice &operator=(const Ice &o);
        virtual ~Ice(void);

        AMateria* clone() const;
        void use(ICharacter& target);
};
