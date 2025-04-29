/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:12:32 by moboulan          #+#    #+#             */
/*   Updated: 2025/04/27 17:07:19 by moboulan         ###   ########.fr       */
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
        
};

std::ostream &operator<<(std::ostream &str, const Fixed &fixed);
#endif
