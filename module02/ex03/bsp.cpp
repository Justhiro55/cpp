/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:41:05 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/29 17:59:20 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed ab_x = b.getX() - a.getX();
    Fixed ab_y = b.getY() - a.getY();
    Fixed bc_x = c.getX() - b.getX();
    Fixed bc_y = c.getY() - b.getY();
    Fixed ca_x = a.getX() - c.getX();
    Fixed ca_y = a.getY() - c.getY();

    Fixed pa_x = point.getX() - a.getX();
    Fixed pa_y = point.getY() - a.getY();
    Fixed pb_x = point.getX() - b.getX();
    Fixed pb_y = point.getY() - b.getY();
    Fixed pc_x = point.getX() - c.getX();
    Fixed pc_y = point.getY() - c.getY();

    bool side1 = (ab_x * pa_y - ab_y * pa_x) >= 0;
    bool side2 = (bc_x * pb_y - bc_y * pb_x) >= 0;
    bool side3 = (ca_x * pc_y - ca_y * pc_x) >= 0;

    if ((side1 == false && side2 == false && side3 == false) || (side1 == true && side2 == true && side3 == true))
    {
        return true;
    }
    return false;
}