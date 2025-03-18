#include "MutantStack.hpp"

int main()
{
    // Test: MutantStack
    std::cout << std::endl;
    std::cout << CYAN << " ----- Testing with MutantStack ----- " << RESET << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "MutantStack:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;
    std::stack<int> s(mstack);
    std::cout << "Size of copied stack: " << s.size() << std::endl;

    // Test: std::list
    std::cout << std::endl;
    std::cout << CYAN << " ----- Testing with std::list ----- " << RESET << std::endl;
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Top: " << lst.back() << std::endl;

    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "list:" << std::endl;
    std::list<int>::iterator lst_it = lst.begin();
    std::list<int>::iterator lst_ite = lst.end();

    ++lst_it;
    --lst_it;

    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << std::endl;
        ++lst_it;
    }
    std::cout << std::endl;

    return 0;
}
