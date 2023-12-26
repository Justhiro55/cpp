/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:06:51 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/26 16:30:40 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    // コンストラクタの実装
    current_index = 0;
    index = 0;
}

PhoneBook::~PhoneBook() {
    // デストラクタの実装
}

void EXIT(void)
{
	std::string command;
	std::cout << "ok? (y/N):";
	getline(std::cin, command);
	if (command == "y" || command == "yes")
	{
		std::cout << "exit" << std::endl;
		exit(EXIT_SUCCESS);
	}
}

int	main(void)
{
    PhoneBook new_address;
	std::string command;
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):";
		getline(std::cin, command);
		if (command.empty())
			continue ;
		if (command == "ADD")
		{
            new_address.ADD();
		}
		else if (command == "SEARCH")
		{
			new_address.SEARCH();
		}
		else if (command == "EXIT")
		{
			EXIT();
		}
		else
		{
			std::cout << "sorry, command not found" << std::endl;
		}
	}
	return (0);
}
