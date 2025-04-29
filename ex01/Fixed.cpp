/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:12:28 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/29 22:54:35 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed::_frac = 8;

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
     _rawBits = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        _rawBits = fixed._rawBits;
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    _rawBits =  (number << _frac);
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
      _rawBits = roundf(number * (1 << _frac));
}

float Fixed::toFloat(void) const
{
    return (float) _rawBits / (1 << _frac);
}

int Fixed::toInt(void) const
{
    return (_rawBits >> _frac);
}

std::ostream    &operator<<(std::ostream &str, const Fixed &fixed)
{
    return (str << fixed.toFloat());   
}
