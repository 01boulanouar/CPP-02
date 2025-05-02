/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:19:07 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/30 15:06:56 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float absolute(const float num)
{
    if (num >= 0)
        return (num);
    else
        return (-num);
}

static float area(const Point p1, const Point p2, const Point p3)
{
    const float x1 = p1.getX().toFloat();
    const float y1 = p1.getY().toFloat();
     
    const float x2 = p2.getX().toFloat();
    const float y2 = p2.getY().toFloat();
    
    const float x3 = p3.getX().toFloat();
    const float y3 = p3.getY().toFloat();

    const float area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;

    return absolute(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    const float a_b_c = area(a, b ,c);
    const float p_a_b = area(point, a, b);
    const float p_b_c = area(point, b, c);
    const float p_a_c = area(point, a, c);

    if (p_a_b == 0 || p_b_c == 0 || p_a_c == 0)
        return (false);
    else if (p_a_b + p_b_c + p_a_c == a_b_c)
        return (true);
    else
        return (false);
}
