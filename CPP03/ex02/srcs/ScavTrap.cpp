#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("SC4V-TP")
{
    m_hit_points = 100;
    m_energy_points = 50;
    m_attack_damage = 20;
    m_message("Claptrap is modified to Scavtrap.");
    m_display_quote(SCTR_JOIN);
}

ScavTrap::~ScavTrap()
{
    m_message("Scavtrap has been destroyed.");
    m_display_quote(SCTR_DEAD);
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    *this = src;
    m_message("Scavtrap is copied.");
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
    ClapTrap::operator=(rhs);
    return (*this);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    m_hit_points = 100;
    m_energy_points = 50;
    m_attack_damage = 20;
    m_message("Claptrap is modified to Scavtrap.");
    m_display_quote(SCTR_JOIN);
}

void ScavTrap::attack(const std::string &target)
{
    if (m_hit_points <= 0)
    {
        m_message("Attack failed.");
        m_display_hp();
        return;
    }
    if (m_energy_points == 0)
    {
        m_message("Attack failed.");
        m_display_hp();
        m_display_ep();
        m_display_quote(SCTR_NOEP);
        return;
    }
    --m_energy_points;
    std::cout << YELLOW << "[MESSAGE] "
              << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage
              << " point of damage." << RESET << std::endl;
    m_display_quote(SCTR_ATTK);
}

void ScavTrap::guardGate()
{
    if (m_hit_points <= 0)
    {
        m_message("Gatekeeper mode activation : FAILED");
        m_display_hp();
        return;
    }
    m_message("ScavTrap Gatekeeper mode activated.");
    m_display_quote(SCTR_GATE);
}
