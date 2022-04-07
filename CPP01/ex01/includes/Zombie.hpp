#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <iostream>
#include <string>

#include "color.hpp"

#define ZOMBIE_SOUND "BraiiiiiiinnnzzzZ..."

class Zombie
{
  private:
    std::string m_name;

  public:
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif