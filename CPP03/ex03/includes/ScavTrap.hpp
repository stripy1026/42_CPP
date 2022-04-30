#ifndef _SCAV_TRAP_HPP_
#define _SCAV_TRAP_HPP_

#include "ClapTrap.hpp"

#define SCTR_JOIN "Hey everybody ! Check out my package !"
#define SCTR_DEAD "Woah ! Oh ! Jeez !"
#define SCTR_ATTK "Heyyah !"
#define SCTR_NOEP "Coming up empty !"
#define SCTR_GATE "This is why I was built !"

class ScavTrap : public ClapTrap
{
  public:
    ScavTrap();
    ~ScavTrap();
    ScavTrap(const ScavTrap &src);
    ScavTrap &operator=(const ScavTrap &rhs);

    ScavTrap(const std::string &name);
    void attack(const std::string &target);
    void guardGate() const;
};

#endif // _SCAV_TRAP_HPP_