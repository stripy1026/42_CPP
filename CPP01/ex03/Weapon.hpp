#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <string>

class Weapon
{
  private:
    std::string m_type;

  public:
	Weapon();
	~Weapon();

    const std::string &getType();
    void setType(std::string type);
};

#endif // _WEAPON_H_