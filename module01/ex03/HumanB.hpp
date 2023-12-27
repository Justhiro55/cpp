/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:17 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 16:10:53 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanB.hpp
#ifndef HumanB_HPP
#define HumanB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    void attack() const;
    void setWeapon(Weapon &weapon);

private:
    std::string _name;
    Weapon *_weapon;
};

#endif