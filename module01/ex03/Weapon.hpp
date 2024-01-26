/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:17 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/26 16:31:13 by hhagiwar         ###   ########.fr       */
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
    const std::string &getType() const;
    void setType(std::string type);

private:
    std::string _type;
};

#endif