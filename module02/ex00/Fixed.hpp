/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:59:26 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/28 17:17:23 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &obj);

    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int value;
    static const int bits = 8;
};

#endif
