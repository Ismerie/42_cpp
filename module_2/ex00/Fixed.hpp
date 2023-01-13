/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:15 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/29 16:49:15 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class   Fixed {
    public :
        Fixed(void);
        Fixed(const Fixed &src);
        ~Fixed(void);

        Fixed   &operator=(const Fixed &other);
        int     getRawBits(void) const;
        void    setRawBits(const int raw);

    private :
        int                 _fixed_point_value;
        static const int    _number_of_fractionnal_bits = 8;
};

#endif