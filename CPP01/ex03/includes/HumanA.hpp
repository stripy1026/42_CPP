#ifndef _HUMAN_A_HPP_
#define _HUMAN_A_HPP_

#include "Weapon.hpp"

class HumanA
{
  private:
    std::string m_name;
    Weapon &m_weapon;

  public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void setName(std::string name);
    void setWeapon(Weapon &weapon);
    void attack() const;
};

#endif // _HUMAN_A_HPP_