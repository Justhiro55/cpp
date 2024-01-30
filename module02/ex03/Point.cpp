/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:41:09 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/29 18:00:14 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Point.cpp
#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(float const x, float const y) : x(x), y(y)
{
}

Point::Point(const Point &point) : x(point.getX()), y(point.getY())
{
}

Point::~Point() {}

Point &Point::operator=(const Point &obj)
{
    if (this != &obj)
    {
        (Fixed) this->x = obj.getX();
        (Fixed) this->y = obj.getY();
    }
    return *this;
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}
