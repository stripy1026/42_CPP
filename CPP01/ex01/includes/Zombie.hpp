#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

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

#endif // _ZOMBIE_HPP_