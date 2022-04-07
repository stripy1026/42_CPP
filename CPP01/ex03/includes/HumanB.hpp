#ifndef _HUMAN_B_HPP_
#define _HUMAN_B_HPP_

#include "Weapon.hpp"

class HumanB
{
  private:
    std::string m_name;
	Weapon *m_weapon;

  public:
    HumanB(std::string name);
    ~HumanB();

    void setName(std::string name);
    void setWeapon(Weapon &weapon);
    void attack() const;
};

#endif // _HUMAN_B_HPP_