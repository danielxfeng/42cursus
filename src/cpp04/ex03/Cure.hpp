# pragma once

# include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure(void);
        Cure(const Cure &o);
        Cure &operator=(const Cure &o);
        virtual ~Cure(void);

        AMateria* clone() const;
        void use(ICharacter& target);
};
