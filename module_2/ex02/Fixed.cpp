/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:23 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/29 16:49:23 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point_value(0) {
    std::cout << "Default Constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixed_point_value = value << this->_number_of_fractionnal_bits;
    return ;
} 

// 1 << _number_of_fractionnale_bits = 2^8
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixed_point_value = roundf(value * (1 << this->_number_of_fractionnal_bits));
    return ;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed   &Fixed::operator=(Fixed const &other) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
        this->_fixed_point_value = other._fixed_point_value;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const {
    return (this->_fixed_point_value > other._fixed_point_value);
}

bool Fixed::operator<(const Fixed &other) const {
    return (this->_fixed_point_value < other._fixed_point_value);
}

bool Fixed::operator>=(const Fixed &other) const {
    return (this->_fixed_point_value >= other._fixed_point_value);
}

bool Fixed::operator<=(const Fixed &other) const {
    return (this->_fixed_point_value <= other._fixed_point_value);
}

bool Fixed::operator==(const Fixed &other) const {
    return (this->_fixed_point_value == other._fixed_point_value);
}

bool Fixed::operator!=(const Fixed &other) const {
    return (this->_fixed_point_value != other._fixed_point_value);
}

Fixed   Fixed::operator+(const Fixed &other) {
    return (this->_fixed_point_value + other._fixed_point_value);
}

Fixed   Fixed::operator-(const Fixed &other) {
    return (this->_fixed_point_value - other._fixed_point_value);
}

Fixed   Fixed::operator*(const Fixed &other) {
    Fixed   result(this->toFloat() * other.toFloat());

    return (result);
}

Fixed   Fixed::operator/(const Fixed &other) {
    Fixed   result(this->toFloat() / other.toFloat());

    return (result);
}

Fixed   &Fixed::operator++(void) {
    this->_fixed_point_value++;
    return (*this);
}

Fixed   Fixed::operator++(int) {
    Fixed   old(*this);

    ++(*this);
    return (old);
}

Fixed   &Fixed::operator--(void) {
    this->_fixed_point_value--;
    return (*this);
}

Fixed   Fixed::operator--(int) {
    Fixed   old(*this);

    --(*this);
    return (old);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return (a);
    else
        return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed   &Fixed::min(Fixed &a,Fixed &b) {
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed   &Fixed::max(Fixed &a,Fixed &b) {
    if (a > b)
        return (a);
    else
        return (b);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed_point_value);
}

void    Fixed::setRawBits(const int raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed_point_value = raw;
    return ;
}

// 1 << _number_of_fractionnale_bits = 2^8
float   Fixed::toFloat(void) const {
    return ((float)this->_fixed_point_value / (float)(1 << _number_of_fractionnal_bits));
}

int Fixed::toInt(void) const {
    return (this->_fixed_point_value >> this->_number_of_fractionnal_bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value) {
    out << value.toFloat();
    return (out);
}
