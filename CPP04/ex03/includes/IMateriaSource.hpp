#ifndef _I_MATERIA_SOURCE_
#define _I_MATERIA_SOURCE_

class IMateriaSource
{
  public:
    virtual ~IMateriaSource()
    {
    }
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // _I_MATERIA_SOURCE_