#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <string>

#define ZOMBIE_SOUND "BraiiiiiiinnnzzzZ..."

class Zombie
{
  private:
    std::string m_name;

  public:
    Zombie();
    ~Zombie();

    void announce(void);
	void setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif