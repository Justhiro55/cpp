/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:59:28 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/02/01 11:39:06 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    this->value = fixed.getRawBits();
}

Fixed::Fixed(int const param)
{
    this->value = param << this->bits;
}

Fixed::Fixed(float const param)
{
    this->value = roundf(param * (1 << this->bits));
}

Fixed::~Fixed()
{
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed& Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
	{
        this->value = obj.getRawBits();
    }
    return *this;
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (this->getRawBits() != obj.getRawBits());
}

bool Fixed::operator>(const Fixed &obj) const
{
    return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (this->getRawBits() <= obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const
{
    Fixed tmp(this->toFloat() + obj.toFloat());
    return tmp;
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    Fixed tmp(this->toFloat() - obj.toFloat());
    return tmp;
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    Fixed tmp(this->toFloat() * obj.toFloat());
    return tmp;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    Fixed tmp(this->toFloat() / obj.toFloat());
    return tmp;
}

Fixed &Fixed::operator++(void)
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    const Fixed tmp(*this);

    this->value++;
    return (tmp);
}

Fixed &Fixed::operator--(void)
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    const Fixed tmp(*this);

    this->value--;
    return (tmp);
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1 >= obj2)
        return obj1;
    return obj2;
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if (obj1 >= obj2)
        return obj1;
    return obj2;
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1 <= obj2)
        return obj1;
    return obj2;
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if (obj1 <= obj2)
        return obj1;
    return obj2;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (1 << this->bits));
}

int Fixed::toInt(void) const
{
    return (this->value >> this->bits);
}
