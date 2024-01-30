/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:59:26 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/29 17:16:07 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed(int const param);
    Fixed(float const param);
    Fixed &operator=(const Fixed &obj);

    bool operator==(const Fixed &obj) const;
    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;

    Fixed operator+(const Fixed &obj) const;
    Fixed operator-(const Fixed &obj) const;
    Fixed operator*(const Fixed &obj) const;
    Fixed operator/(const Fixed &obj) const;

    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);

    static Fixed &max(Fixed &obj1, Fixed &obj2);
    static const Fixed &max(Fixed const &obj1, Fixed const &obj2);
    static Fixed &min(Fixed &obj1, Fixed &obj2);
    static const Fixed &min(Fixed const &obj1, Fixed const &obj2);

    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int value;
    static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
