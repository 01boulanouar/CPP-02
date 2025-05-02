/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:13:22 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/30 15:08:27 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &point): _x(point._x) , _y(point._y) 
{
}

Point &Point::operator=(const Point &point)
{
    (void) point;
    return (*this);
}

Point::~Point()
{
    
}
Fixed const &Point::getX(void) const
{
    return (_x);
}

Fixed const &Point::getY(void) const
{
    return (_y);
}

std::ostream &operator<<(std::ostream &str, const Point &point)
{
    return (str << "(x = " << point.getX().toFloat() << " ; " << "y = " << point.getY().toFloat() << ")");   
}
