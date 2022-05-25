#ifndef _I_CHARACTER_HPP_
#define _I_CHARACTER_HPP_

#include <iostream>

#include "color.hpp"

class AMateria;

class ICharacter
{
  public:
    virtual ~ICharacter()
    {
    }
    virtual const std::string &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};

#endif // _I_CHARACTER_HPP_