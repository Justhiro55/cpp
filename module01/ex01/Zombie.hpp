/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:17 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 10:54:21 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Zombie.hpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
    Zombie();
    Zombie(std::string zombie);
    ~Zombie();
    void announce();
    void setName(std::string name);

private:
    std::string _name;
};
Zombie *zombieHorde(int N,std::string name);

#endif