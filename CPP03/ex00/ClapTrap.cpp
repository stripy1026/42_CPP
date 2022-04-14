#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name("CL4P-TP"), m_hit_points(10), m_energy_points(10), m_attack_damage(0)
{
    m_message("Claptrap has been built.");
    m_display_quote(CLTR_JOIN);
}

void ClapTrap::m_message(const std::string &msg) const
{
    std::cout << YELLOW << "[MESSAGE] " << msg << RESET << std::endl;
}

void ClapTrap::m_display_interaction(const std::string &kind, const int amount, const std::string &target) const
{
    std::cout << YELLOW << "[INTERACTION] " << kind << " = " << amount << " TO " << target << RESET << std::endl;
}

void ClapTrap::m_display_quote(const std::string &msg) const
{
    std::cout << GREEN << "(" << m_name << ") " << RESET << msg << std::endl;
}

void ClapTrap::m_display_hp() const
{
    std::cout << YELLOW << m_name << " HP : " << RESET << m_hit_points << std::endl;
}

void ClapTrap::m_display_ep() const
{
    std::cout << YELLOW << m_name << " EP : " << RESET << m_energy_points << std::endl;
}

ClapTrap::~ClapTrap()
{
    m_message("Claptrap has been destroyed.");
    std::cout << CLTR_DEAD << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
    : m_name(src.m_name), m_hit_points(src.m_hit_points), m_energy_points(src.m_energy_points),
      m_attack_damage(src.m_attack_damage)
{
    m_message("Claptrap is copied.");
    m_display_quote(CLTR_SELT);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    if (this == &rhs)
        return (*this);
    m_name = rhs.m_name;
    m_hit_points = rhs.m_hit_points;
    m_energy_points = rhs.m_energy_points;
    m_attack_damage = rhs.m_attack_damage;
    m_message("Claptrap is copied using assginment operator.");
    m_display_quote(CLTR_SELT);

    return (*this);
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hit_points(10), m_energy_points(10), m_attack_damage(0)
{
    m_message("Claptrap has been built.");
    m_display_quote(CLTR_JOIN);
}

void ClapTrap::attack(const std::string &target)
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
        m_display_quote(CLTR_NOEP);
        return;
    }
    --m_energy_points;
    std::cout << YELLOW << "[MESSAGE] "
              << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage
              << " point of damage." << RESET << std::endl;
    m_display_quote(CLTR_ATTK);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (m_hit_points <= 0)
    {
        m_message("This one is already down.");
        m_display_hp();
        return;
    }
    if (m_hit_points > 0)
    {
        m_hit_points -= amount;
        m_message("Claptrap has been damaged.");
        m_display_interaction("DMG", amount, m_name);
        m_display_quote(CLTR_TDMG);
        m_display_hp();
    }
    if (m_hit_points <= 0)
    {
        m_message("A Claptrap has been down.");
        m_display_quote(CLTR_DOWN);
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (m_hit_points <= 0)
    {
        m_message("Repair failed.");
        m_display_hp();
        return;
    }
    if (m_energy_points == 0)
    {
        m_message("Repair failed.");
        m_display_hp();
        m_display_ep();
        m_display_quote(CLTR_NOEP);
        return;
    }
    --m_energy_points;
    m_hit_points += amount;
    m_message("Claptrap repaired.");
    m_display_interaction("REPAIR", amount, m_name);
    m_display_hp();
    m_display_ep();
    m_display_quote(CLTR_REPA);
}
