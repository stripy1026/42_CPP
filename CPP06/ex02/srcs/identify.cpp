#include "identify.hpp"

Base *generate()
{
    switch (std::rand() % 3)
    {
    case 0:
        return (new A());
    case 1:
        return (new B());
    }
    return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "pointer p: A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "pointer p: B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "pointer p: C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "reference p: A" << std::endl;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "reference p: B" << std::endl;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "reference p: C" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
}
