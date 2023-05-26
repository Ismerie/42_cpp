/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:49:17 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/15 20:49:17 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void   iter(T *tab, int size, void (*fctToExecute)(const T &)){
    for (int i = 0; i < size; i++)
        fctToExecute(tab[i]);
    return ;
}

#endif
