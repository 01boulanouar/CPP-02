/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:12:32 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/30 11:27:47 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H

# define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int _rawBits;
        static const int _frac;
    public:
        Fixed(void);
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);

        Fixed(const int number);
        Fixed(const float number);
        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(const Fixed &fixed) const;
        bool operator<(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;

        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;

        Fixed &operator++(void);
        Fixed &operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);


        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(Fixed const &a,Fixed const &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(Fixed const &a,Fixed const &b);
};

std::ostream &operator<<(std::ostream &str, const Fixed &fixed);
#endif
