/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:12:28 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/30 14:01:38 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed::_frac = 8;

int Fixed::getRawBits(void) const
{
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

Fixed::Fixed(void)
{
     _rawBits = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        _rawBits = fixed._rawBits;
    return *this;
}

Fixed::~Fixed(void)
{
}


Fixed::Fixed(const int number)
{
    _rawBits =  (number << _frac);
}

Fixed::Fixed(const float number)
{
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

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    _rawBits++;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    _rawBits--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed c = *this;
    ++(*this);
    return (c);
}

Fixed Fixed::operator--(int)
{
    Fixed c = *this;
    --(*this);
    return (c);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::min(Fixed const &a,Fixed const &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::max(Fixed const &a,Fixed const &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b); 
}
