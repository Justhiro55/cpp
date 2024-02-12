#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << CYAN << "Constructor" << RESET << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongCat();

    std::cout << std::endl << CYAN << "getType" << RESET << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl << CYAN << "makeSound" << RESET << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    wrong->makeSound();

    std::cout << std::endl << CYAN << "Destructor" << RESET << std::endl;
    delete meta;
    delete j;
    delete i;
    delete wrong;

    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }
