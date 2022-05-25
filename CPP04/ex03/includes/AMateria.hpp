#ifndef _AMETERIA_HPP_
#define _AMETERIA_HPP_

#include "ICharacter.hpp"

class AMateria
{
  protected:
    std::string m_type;

    AMateria();

  public:
    virtual ~AMateria();
    AMateria(const AMateria &src);
    AMateria &operator=(const AMateria &rhs);

    AMateria(const std::string &type);
    const std::string &getType() const;

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif // _AMETERIA_HPP_
