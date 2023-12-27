/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:17 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 10:44:41 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.hpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    Zombie(std::string zombie);
    ~Zombie();
    void announce();

private:
    std::string _name;
};
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif