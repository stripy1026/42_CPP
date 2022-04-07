#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include <string>

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

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif // _ZOMBIE_HPP_