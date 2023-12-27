/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:34:01 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 10:45:09 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\a" << std::endl;
}
