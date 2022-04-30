#ifndef _FRAG_TRAP_HPP_
#define _FRAG_TRAP_HPP_

#include "ClapTrap.hpp"

#define FRTR_JOIN "Get ready for some Fragtrap face time !"
#define FRTR_DEAD "My robotic flesh ! AAHH !"
#define FRTR_HIFV "*high-five* Up top !"

class FragTrap : public ClapTrap
{
  public:
    FragTrap();
    ~FragTrap();
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &rhs);

    FragTrap(const std::string &name);
    void highFiveGuys() const;
};

#endif // _FRAG_TRAP_HPP_
