#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(std::string name);
    	Cat(const Cat& obj);
        ~Cat();
        Cat &operator=(const Cat &obj);
        void makeSound() const;
        std::string getBrainIdea(int index) const;
        void setBrainIdea(int index, const std::string& idea);
    private:
        Brain *brain;
};

#endif