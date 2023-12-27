/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:17 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 14:56:11 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Weapon.hpp
#ifndef Weapon_HPP
#define Weapon_HPP

#include <iostream>

class Weapon
{
public:
    Weapon();
    Weapon(std::string);
    ~Weapon();
    std::string getType() const;
    void setType(std::string type);

private:
    std::string _type;
};

#endif