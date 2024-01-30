/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:06:45 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/22 20:36:18 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void	Contact::PrintAllContact(void)
{
	std::cout << "first name : " << this->firstname << std::endl;
	std::cout << "last name : " << this->lastname << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->number << std::endl;
}

void	PhoneBook::SEARCH(void)
{
	int i;
	int number;

	i = 0;
	if (this->current_index ==0)
		std::cout << "Your PhoneBook is empty." << std::endl;
	else
	{
		std::cout 	<< "     index" << "|" \
					<< "first name" << "|" \
					<< " last name" << "|" \
					<< "  nickname" << "|" << std::endl;
		while (i < this->current_index && i < 8)
		{
			std::cout << "         " << i + 1;
			contacts[i].PrintShortContact();
			i++;
		}
		std::cout << "Which index: " << std::endl;
		std::cin >> number;
		std::cin.clear();
		std::cin.ignore(255, '\n');
		if (std::cin.fail())
		{
			std::cout << "Wrong input" << std::endl;
			return ;
		}
		else 
		{
			number = number - 1;
			if (number <= 7 && number >= 0 && number < this->current_index)
				contacts[number].show_db_row(number);
			else
				std::cout << "Out of range" << std::endl;			
		}
	}
}

void 	Contact::copy_contacts(Contact contact)
{
	lastname = contact.lastname;
	firstname = contact.firstname;
	number = contact.firstname;
	nickname = contact.nickname;
	darkestsecret = contact.darkestsecret;
}

void	PhoneBook::ADD(void)
{
    if (current_index < 8) {
		std::cout << "index" << current_index << std::endl;
        contacts[current_index].AddContent();
		std::cout << "[successfully added]" << std::endl;
    } else {
        for(int i = 0; i < 7; i++) {
            contacts[i].copy_contacts(contacts[i+1]);
        }
		contacts[7].AddContent();
    }
    current_index++;
}
