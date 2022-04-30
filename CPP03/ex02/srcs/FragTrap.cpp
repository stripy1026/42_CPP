#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FR4G-TP")
{
    m_hit_points = 100;
    m_energy_points = 100;
    m_attack_damage = 30;
    m_message("Claptrap is modified to Fragtrap.");
    m_display_quote(FRTR_JOIN);
}

FragTrap::~FragTrap()
{
    m_message("Fragtrap has been destroyed.");
    m_display_quote(FRTR_DEAD);
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    *this = src;
    m_message("FragTrap is copied.");
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    m_hit_points = 100;
    m_energy_points = 100;
    m_attack_damage = 30;
    m_message("Claptrap is modified to FragTrap.");
    m_display_quote(FRTR_JOIN);
}

void FragTrap::highFiveGuys() const
{
    if (m_hit_points <= 0)
    {
        m_message("Requesting High-five : FAILED");
        m_display_hp();
        return;
    }
	m_message("Requesting High-five received.");
	m_display_quote(FRTR_HIFV);
}
