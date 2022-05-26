#ifndef _MATERIA_SOURCE_HPP_
#define _MATERIA_SOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    static const int m_source_size = 4;
    AMateria *m_sources[m_source_size];
    int m_source_slot;

  public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &src);
    MateriaSource &operator=(const MateriaSource &rhs);

    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif // _MATERIA_SOURCE_HPP_
