/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:13:22 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/30 14:02:03 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &point)
{
    *this = point;
}

Point &Point::operator=(const Point &point)
{
    if (this != &point)
       *this = point;
    return (*this);
}

Point::~Point()
{
    
}
Fixed const Point::getX(void) const
{
    return (_x);
}

Fixed const Point::getY(void) const
{
    return (_y);    
}
