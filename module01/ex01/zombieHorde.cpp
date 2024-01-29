/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:38:44 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/29 10:19:05 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if( N < 1 )
    {
        std::cout << "Error" << std::endl;
        return NULL;
    }
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name + std::to_string(i + 1));
        horde[i].announce();
    }
    return horde;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}
