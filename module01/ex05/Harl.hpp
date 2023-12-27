/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:17 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 18:32:40 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Harl.hpp
#ifndef Harl_HPP
#define Harl_HPP

#include <iostream>

class Harl
{
public:
    void complain(std::string level);

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif