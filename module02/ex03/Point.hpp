/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:41:12 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/29 17:41:29 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Point.hpp

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
public:
    Point();
    Point(float num1, float num2);
    Point(const Point &obj);
    ~Point();
    
    Point &operator=(const Point &obj);

    Fixed getX() const;
    Fixed getY() const;

private:
    Fixed const x;
    Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
