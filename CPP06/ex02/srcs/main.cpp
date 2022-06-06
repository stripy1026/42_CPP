#include "identify.hpp"

int main()
{
    srand(time(NULL));
    Base *p = generate();
    identify(p);
    identify(*p);
    return (0);
}
