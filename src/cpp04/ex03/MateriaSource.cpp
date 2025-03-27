# include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; ++i)
        materias_[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &o) {
    for (int i = 0; i < 4; ++i) {
        if (o.materias_[i])
            materias_[i] = o.materias_[i]->clone();
        else
            materias_[i] = nullptr;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &o) {
    if (this == &o)
        return *this;
    for (int i = 0; i < 4; ++i) {
        if (materias_[i])
            delete materias_[i];
        if (o.materias_[i])
            materias_[i] = o.materias_[i]->clone();
        else
            materias_[i] = nullptr;
    }
    return *this;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; ++i) {
        if (materias_[i])
            delete materias_[i];
        materias_[i] = nullptr;
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (materias_[i] == m) {
            return;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (!materias_[i]) {
            materias_[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (materias_[i] && materias_[i]->getType() == type) {
            return materias_[i]->clone();
        }
    }
    return nullptr;
}
