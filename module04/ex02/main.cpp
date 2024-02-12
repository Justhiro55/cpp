#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // Animal animal;

    Dog* dog = new Dog();
    Cat* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}


// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q out");
// }
