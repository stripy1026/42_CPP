#ifndef _DIAMOND_TRAP_HPP_
#define _DIAMOND_TRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define DITR_JOIN "GeT$eAb@y_for^s@M=Ou%pAC#aGYoU ?"
#define DITR_DEAD "Rob@t%CjE#ZzSh !"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
    std::string m_name;

  public:
    DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap &operator=(const DiamondTrap &rhs);

	DiamondTrap(const std::string &name);
	void whoAmI() const;
	using ScavTrap::attack;
};

#endif // _DIAMOND_TRAP_HPP_