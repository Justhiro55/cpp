#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<iostream>

class Brain
{
    public:
        Brain();
        Brain(Brain &obj);
    	Brain(const Brain& obj);
        virtual ~Brain();
        Brain &operator=(const Brain &obj);
        Brain *getBrain() const;
        void setBrain(std::string idea, int index);

    private:
        std::string _ideas[100];
};

#endif