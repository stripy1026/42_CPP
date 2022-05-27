#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *animals[10];
    for (int i = 0; i < 10; ++i)
        i % 2 == 0 ? animals[i] = new Cat() : animals[i] = new Dog();

    for (int i = 0; i < 10; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 10; ++i)
        delete animals[i];
    {
        std::cout << YELLOW << "=== COPY CAT TEST ===" << RESET << std::endl;
        Cat cat1;
        cat1.setIdeas(0, "Eat");
        std::cout << YELLOW << "+copy constructor" << RESET << std::endl;
        Cat cat2 = cat1;
        std::cout << YELLOW << "+copy assignment opeartor" << RESET << std::endl;
        Cat cat3;
        cat3 = cat1;

        std::cout << YELLOW << "+tests" << RESET << std::endl;
        std::cout << cat1.getIdeas(0) << " == " << cat3.getIdeas(0) << std::endl;
        cat1.setIdeas(0, "Sleep");
        std::cout << cat1.getIdeas(0) << " != " << cat3.getIdeas(0) << std::endl;

        std::cout << YELLOW << "+destructions" << RESET << std::endl;
    }
    {
        std::cout << YELLOW << "=== COPY DOG TEST ===" << RESET << std::endl;
        Dog dog1;
        dog1.setIdeas(0, "Eat");
        std::cout << YELLOW << "+copy constructor" << RESET << std::endl;
        Dog dog2 = dog1;
        std::cout << YELLOW << "+copy assignment opeartor" << RESET << std::endl;
        Dog dog3;
        dog3 = dog1;

        std::cout << YELLOW << "+tests" << RESET << std::endl;
        std::cout << dog1.getIdeas(0) << " == " << dog3.getIdeas(0) << std::endl;
        dog1.setIdeas(0, "Sleep");
        std::cout << dog1.getIdeas(0) << " != " << dog3.getIdeas(0) << std::endl;

        std::cout << YELLOW << "+destructions" << RESET << std::endl;
    }
	system("leaks the_ink_spot");
    return (0);
}
