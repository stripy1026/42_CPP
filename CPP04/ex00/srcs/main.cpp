#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << YELLOW << "=== WRONG ANIMAL TESTS ===" << RESET << std::endl;
    const WrongAnimal *k = new WrongCat();

    std::cout << YELLOW << "cat sounds : " << RESET;
    k->makeSound();

    delete k;

	system("leaks polymorphism");
    return (0);
}
