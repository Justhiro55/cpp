/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:31:22 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 15:13:55 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string name)
{
    this->_type = name;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

std::string Weapon::getType() const
{
    return this->_type;
}
