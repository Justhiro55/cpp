#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>

Base* generate(void) {
    int random;

    std::srand(time(NULL));
    random = std::rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << GREEN << "A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << BLUE << "B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << MAGENTA <<  "C" << RESET << std::endl;
}

void identify(Base& p) {
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << GREEN << "A" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << BLUE << "B" << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << MAGENTA <<  "C" << RESET << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

int main(void)
{
    Base *base;

    base = generate();

    std::cout << "Identify by pointer: " << std::endl;
    identify(base);
    std::cout << std::endl;

    std::cout << "Identify by reference: " << std::endl;
    identify(*base);
    std::cout << std::endl;

    delete base;
    return 0;
}
