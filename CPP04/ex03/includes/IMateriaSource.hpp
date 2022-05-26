#ifndef _I_MATERIA_SOURCE_HPP_
#define _I_MATERIA_SOURCE_HPP_

#include "AMateria.hpp"

class IMateriaSource
{
  public:
    virtual ~IMateriaSource()
    {
    }
    virtual void learnMateria(AMateria *m) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // _I_MATERIA_SOURCE_HPP_