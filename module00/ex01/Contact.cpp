/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:06:49 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/26 16:31:53 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
    // コンストラクタの実装
    lastname = "";
    firstname = "";
    number = "";
	nickname = "";
	darkestsecret = "";
}

Contact::~Contact() {
    // デストラクタの実装
}

void    Contact::AddContent()
{
	this->lastname = "";
    while (this->lastname.empty()){
        std::cout << "lastname is  : ";
	    getline(std::cin, this->lastname);
		if (this->lastname[0] == ' ')
			this->lastname = "";
    }
	this->firstname = "";
    while (this->firstname.empty()){
        std::cout << "firstname is : ";
	    getline(std::cin, this->firstname);
		if (this->firstname[0] == ' ')
			this->firstname = "";
    }
	this->number = "";
    while (this->number.empty()){
        std::cout << "number is    : ";
    	getline(std::cin, this->number);
		if (this->number[0] == ' ')
			this->number = "";
    }
	this->nickname = "";
    while (this->nickname.empty()){
        std::cout << "nickname is  : ";
    	getline(std::cin, this->nickname);
		if (this->nickname[0] == ' ')
			this->nickname = "";
    }
	this->darkestsecret = "";
    while (this->darkestsecret.empty()){
        std::cout << "darkest secret is  : ";
    	getline(std::cin, this->darkestsecret);
		if (this->darkestsecret[0] == ' ')
			this->darkestsecret = "";
    }
}

std::string Contact::getShortStr(std::string str)
{
	if ((str.size()) > 10)
		return (str.substr(0, 9) + ".");
	else
		return (std::string(10 - (str.size()), ' ') + str);
}

void	Contact::PrintShortContact(void)
{
	std::cout	<< "|" << getShortStr(this->firstname) \
				<< "|" << getShortStr(this->lastname) \
				<< "|" << getShortStr(this->nickname) \
				<< "|" << std::endl;
}

bool Contact::show_db_row(int index) const
{
	if (this->lastname == "")
		return false;
	std::cout << " ----------------" << std::endl;
	std::cout << "  index[" << index + 1 << "]" << std::endl;
	std::cout << "  lastname:  [ " << this->lastname << " ]" << std::endl;
	std::cout << "  firstname: [ " << this->lastname << " ]" << std::endl;
	std::cout << "  nickname:  [ " << this->nickname << " ]" << std::endl;
	std::cout << "  number:    [ " << this->number << " ]" << std::endl;
	std::cout << " ----------------" << std::endl;
	return true;
}
