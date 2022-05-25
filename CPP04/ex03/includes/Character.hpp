#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include "AMateria.hpp"

class Character : public ICharacter
{
  private:
    static const int m_inventory_size = 4;
    AMateria *m_inventory[m_inventory_size];
    std::string m_name;

    Character();

  public:
    ~Character();
    Character(const Character &src);
    Character &operator=(const Character &rhs);

    Character(const std::string &name);
    const std::string &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif // _CHARACTER_HPP_
