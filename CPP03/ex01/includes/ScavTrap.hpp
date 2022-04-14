#ifndef _SCAV_TRAP_HPP_
#define _SCAV_TRAP_HPP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
    ScavTrap();
    ~ScavTrap();
    ScavTrap(const ScavTrap &src);
    ScavTrap &operator=(const ScavTrap &rhs);

    ScavTrap(const std::string &name);
    void attack(const std::string &target);
    void guardGate();
};

#endif // _SCAV_TRAP_HPP_