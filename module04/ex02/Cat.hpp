#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
    public:
        Cat();
    	Cat(const Cat& obj);
        ~Cat();
        Cat &operator=(const Cat &obj);
        void makeSound() const;
        std::string getBrainIdea(unsigned int index) const;
        void setBrainIdea(unsigned int index, const std::string& idea);
    private:
        Brain *brain;
};

#endif