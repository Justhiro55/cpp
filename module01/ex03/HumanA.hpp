/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:17 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 16:04:40 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanA.hpp
#ifndef HumanA_HPP
#define HumanA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack() const;
    void setWeapon(Weapon weapon);

private:
    Weapon &_weapon;
    std::string _name;
};

#endif