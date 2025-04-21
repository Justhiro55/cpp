#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << CYAN << std::endl << "--- Vector test ---" << RESET << std::endl;
    try {
        // normal case
        std::cout << "Finding 1 in vector: " << std::endl;
        std::cout << "Found at " << std::distance(vec.begin(), easyfind(vec, 1)) << std::endl << std::endl;

        std::cout << "Finding 3 in vector: " << std::endl;
        std::cout << "Found at " << std::distance(vec.begin(), easyfind(vec, 3)) << std::endl << std::endl;

        // exception case
        std::cout << "Finding 10 in vector: " << std::endl;;
        vec.begin(), easyfind(vec, 10);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    std::cout << CYAN << "--- List test ---" << RESET << std::endl;
    try {
        // normal case
        std::cout << "Finding 30 in list: " << std::endl;
        std::cout << "Found at " << std::distance(lst.begin(), easyfind(lst, 30)) << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
