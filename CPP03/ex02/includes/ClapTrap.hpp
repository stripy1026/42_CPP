#ifndef _CLAP_TRAP_HPP_
#define _CLAP_TRAP_HPP_

#include <iostream>
#include <string>

#include "color.hpp"

#define CLTR_JOIN "You want me ? To join you ? I am SO excited. We will be best friends."
#define CLTR_SELT "Recompiling my combat code !"
#define CLTR_DEAD "Argh arghargh death gurgle gurglegurgle urgh ... death."
#define CLTR_ATTK "Take that !"
#define CLTR_TDMG "Oh my God, I'm leaking ! I think I'm leaking ! Ahhhh, I'm leaking ! There's oil everywhere !"
#define CLTR_NOEP "Dangit, I'm out !"
#define CLTR_REPA "Sweet life juice !"
#define CLTR_DOWN "Robot down !"

class ClapTrap
{
  protected:
    std::string m_name;
    int m_hit_points;
    unsigned int m_energy_points;
    int m_attack_damage;

    void m_message(const std::string &msg) const;
    void m_display_quote(const std::string &msg) const;
    void m_display_interaction(const std::string &kind, const int amount, const std::string &target) const;
    void m_display_hp() const;
    void m_display_ep() const;

  public:
    ClapTrap();
    ~ClapTrap();
    ClapTrap(const ClapTrap &src);
    ClapTrap &operator=(const ClapTrap &rhs);

    ClapTrap(std::string name);
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // _CLAP_TRAP_HPP_