#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DI4M_TP_clap_name"), ScavTrap(), FragTrap()
{
    m_name = "DI4M_TP";
    m_hit_points = FragTrap::m_hit_points;
    m_energy_points = ScavTrap::m_energy_points;
    m_attack_damage = FragTrap::m_attack_damage;
    m_message("WARNING : DiamondTrap is highly unstable.");
    m_display_quote(DITR_JOIN);
}

DiamondTrap::~DiamondTrap()
{
    m_message("DiamondTrap has melting down.");
    m_display_quote(DITR_DEAD);
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
    *this = src;
    m_message("DiamondTrap is copied.");
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	ClapTrap::operator=(rhs);
    m_name = rhs.m_name;
    return (*this);
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
    m_name = name;
    m_hit_points = FragTrap::m_hit_points;
    m_energy_points = ScavTrap::m_energy_points;
    m_attack_damage = FragTrap::m_attack_damage;
    m_message("WARNING : DiamondTrap is highly unstable.");
    m_display_quote(DITR_JOIN);
}

void DiamondTrap::whoAmI() const
{
    m_message("WARNING : DiamondTrap is confusing what itself is.");
    std::cout << GREEN << "(" << m_name << ") " << RESET << "Wh@AmI ?? " << m_name << " ? " << ClapTrap::m_name << " ?"
              << std::endl;
}
