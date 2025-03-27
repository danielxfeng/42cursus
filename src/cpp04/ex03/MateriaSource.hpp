# pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &o);
        MateriaSource &operator=(const MateriaSource &o);
        virtual ~MateriaSource(void);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);

    private:
        AMateria *materias_[4];
};
