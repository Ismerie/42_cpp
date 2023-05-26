/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:03:10 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/18 13:03:10 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int goal) {
    typename T::iterator    result;

    result = std::find(container.begin(), container.end(), goal);
    return (result);
}

#endif
