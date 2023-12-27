/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:31:22 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 16:09:54 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
    this->_weapon = weapon;
    this->_name = name;
}

HumanA::~HumanA()
{
}

void HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}

void HumanA::attack() const
{
    std::cout << "\033[36m" << this->_name << "\033[0m attack with their " << this->_weapon.getType() << std::endl;
}
