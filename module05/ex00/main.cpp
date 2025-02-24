#include "Bureaucrat.hpp"

int main()
{
	try{
		std::cout << std::endl;

		Bureaucrat bureaucrat("test", 150);
		std::cout << bureaucrat << std::endl;

		std::cout << GREEN << "[incrementGrade]" << RESET << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		std::cout << GREEN << "[decrementGrade]" << RESET << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	std::cout << "======error check======" << std::endl;
	// errorcase 1: tooLow
	try {
		std::cout << "[tooLow case]" << std::endl;
		Bureaucrat toolow("testcase_tooHigh", 151);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// errorcase 2: tooHigh
	try {
		std::cout << "[tooHigh case]" << std::endl;
		Bureaucrat toohigh("testcase_tooLow", 0);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// errorcase 3: minus
	try {
		std::cout << "[minus case]" << std::endl;
		Bureaucrat toohigh("testcase_minus", -1);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// errorcase 4: exceed high grade
	try {
		std::cout << "[exceed high grade]" << std::endl;
		Bureaucrat exceedMax("exceed_max", 1);
		exceedMax.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	// errorcase 5: exceed low grade
	try {
		std::cout << "[exceed low grade]" << std::endl;
		Bureaucrat exceedMin("exceed_min", 150);
		exceedMin.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;

	return (0);
}

// __attribute__((destructor))
// static void destructor()
// {
//     system("leaks -q bureaucrat");
// }
