#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    Animal* animals[10];

    std::cout << "---array test---" << std::endl;
    std::cout << "Creating animals..." << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i + 1 << "." << std::endl;
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl;
    std::cout << "--makesound--" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i + 1 << "." << std::endl;
        animals[i]->makeSound();
    }

    std::cout << std::endl;
    std::cout << "--Deleting animals...--" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << i + 1 << "." << std::endl;
        delete animals[i];
    }

    std::cout << std::endl;
    std::cout << "---Deep copy test---" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->setBrainIdea(0, "Original Dog's Idea");

    Dog* copyDog = new Dog(*originalDog);
    copyDog->setBrainIdea(0, "Copy Dog's Idea");

    Cat* originalCat = new Cat();
    originalCat->setBrainIdea(0, "Original Cat's Idea");

    Cat* copyCat = new Cat(*originalCat);
    copyCat->setBrainIdea(0, "Copy Cat's Idea");

    std::cout << std::endl;
    std::cout << "--test output--" << std::endl;
    std::cout << CYAN << "Original Dog's Idea: " << originalDog->getBrainIdea(0) << std::endl;
    std::cout << "Copy Dog's Idea    : " << copyDog->getBrainIdea(0) << RESET << std::endl;
    std::cout << std::endl;
    std::cout << MAGENTA << "Original Cat's Idea: " << originalCat->getBrainIdea(0) << std::endl;
    std::cout << "Copy Cat's Idea    : " << copyCat->getBrainIdea(0) << RESET << std::endl;
    std::cout << std::endl;

    delete originalDog;
    delete copyDog;
    delete originalCat;
    delete copyCat;

    std::cout << std::endl;
    std::cout << "---Testing invalid index access---" << std::endl;
    Dog dog;
    Cat cat;

    std::cout << std::endl;
    std::cout << "--test--" << std::endl;
    std::cout << CYAN;
    dog.setBrainIdea(100, "Dog's invalid idea");
    dog.setBrainIdea(-100, "Dog's invalid idea");
    std::cout << "Dog's Idea at 100: " << dog.getBrainIdea(100);
    std::cout << "Dog's Idea at 99: " << dog.getBrainIdea(99);
    std::cout << std::endl;
    std::cout << RESET;

    std::cout << MAGENTA;
    cat.setBrainIdea(100, "Cat's invalid idea");
    dog.setBrainIdea(-100, "Dog's invalid idea");
    std::cout << "Cat's Idea at 100: " << cat.getBrainIdea(100);
    std::cout << "Cat's Idea at 99: " << cat.getBrainIdea(99);
    std::cout << RESET;

    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }
