/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:18:12 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/15 20:18:12 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void    swap(T &x, T &y) {
    T tmp = x;

    x = y;
    y = tmp;
}

template<typename T>
T const &max(T const & x, T const & y) {
    return (x > y ? x : y);
}

template<typename T>
T const &min(T const & x, T const & y) {
    return (x < y ? x : y);
}

#endif