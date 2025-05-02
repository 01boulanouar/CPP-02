/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:20:17 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/30 15:10:46 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a;
    Point b(0, 5.5);
    Point c(5.5, 0);

    Point point(2.5, 2.5);
 
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    
    std::cout << "point 1: " << point << std::endl;
    
    if (bsp(a, b, c, point))
        std::cout << "the point is inside the triangle" << std::endl;
    else
       std::cout << "the point is NOT inside the triangle" << std::endl;

    Point point2(10, 15.12);

    std::cout << "point 2: " << point2 << std::endl;
 
    if (bsp(a, b, c, point2))
        std::cout << "the point2 is inside the triangle" << std::endl;
    else
       std::cout << "the point2 is NOT inside the triangle" << std::endl;

    return (0);
}
