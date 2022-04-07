#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <string>

class Weapon
{
  private:
    std::string m_type;

  public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();

    std::string const &getType() const;
    void setType(std::string type);
};

#endif // _WEAPON_HPP_