/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:05:06 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/18 14:05:06 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(void) : _max(0), _number_add(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Span::Span(unsigned int max) : _max(max), _number_add(0) {
    std::cout << "Constructor called" << std::endl;
    return ;
}

Span::Span(const Span &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Span::~Span(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Span    &Span::operator=(const Span &other) {
    std::cout << "Assignment operator called" << std::endl;
    this->_max = other._max;
    this->_vect = other._vect;
    this->_number_add = other._number_add;
    return (*this);
}

//functions

void    Span::addNumber(int number) {
    if (this->_number_add < this->_max) {
        this->_vect.push_back(number);
        this->_number_add++;
    }
    else
        throw Span::FullSpanException();
    return ;
}

void    Span::addByIteratorRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::vector<int>    tmp(begin, end);

    if (tmp.size() > (this->_max - this->_number_add))
        throw Span::FullSpanException();
    else
        copy(tmp.begin(), tmp.end(), std::back_inserter(this->_vect));
    this->_number_add += tmp.size();
    return ;
}

int Span::shortestSpan(void) const {
    if (this->_number_add <= 1)
        throw   Span::NotEnoughNumbersException();

    std::vector<int>                    tmp = this->_vect;
    std::vector<int>::iterator          first, next;
    int                                 min_diff, diff;

    std::sort(tmp.begin(), tmp.end());
    first = tmp.begin();
    next = tmp.begin() + 1;
    min_diff = std::abs(*next++ - *first++);
    while (next != tmp.end()) {
        diff = std::abs(*next++ - *first++);
        if (diff < min_diff)
            min_diff = diff;
    }
    return (min_diff);
}

int Span::longestSpan(void) const {
    if (this->_number_add <= 1)
		throw Span::NotEnoughNumbersException();

	int biggest = *std::max_element(this->_vect.begin(), this->_vect.end());
	int smallest = *std::min_element(this->_vect.begin(), this->_vect.end());
	return (std::abs(biggest - smallest));
}
