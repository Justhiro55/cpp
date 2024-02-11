#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<iostream>

class Brain
{
    public:
        Brain();
    	Brain(const Brain& obj);
        ~Brain();
        Brain &operator=(Brain &obj);
        std::string getIdea(unsigned int index) const;
        void setIdea(std::string idea, unsigned int index);

    private:
        std::string *_ideas;
};

#endif