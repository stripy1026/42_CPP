#ifndef _CURE_HPP_
#define _CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria
{
  public:
    Cure();
    ~Cure();
    Cure(const Cure &src);
    Cure &operator=(const Cure &rhs);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif // _CURE_HPP_