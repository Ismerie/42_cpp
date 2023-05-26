/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:04:53 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/18 14:04:53 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
    public :
        Span(void);
        Span(unsigned int max);
        Span(const Span &src);
        ~Span(void);

        Span    &operator=(const Span &other);

        void    addNumber(int number);
        void    addByIteratorRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan(void) const;
        int     longestSpan(void) const;

        class FullSpanException: public std::exception {
            virtual const char* what() const throw() {
                return ("Exception: Span is full");
            }
        };
        class NotEnoughNumbersException: public std::exception {
            virtual const char* what() const throw() {
                return ("Exception: Not enough numbers");
            }
        };

    private :
        unsigned int        _max;
        unsigned int        _number_add;
        std::vector<int>    _vect;
};

#endif
