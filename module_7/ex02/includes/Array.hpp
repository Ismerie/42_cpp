/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:34:59 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/16 12:34:59 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template<typename T>
class Array {
    public :
        Array<T>(void): _size(0), _array(NULL)
        {
            std::cout << "Default constructor called" << std::endl;
            return ;
        }
        Array<T>(const unsigned int n): _size(n)
        {
            std::cout << "Size constructor called" << std::endl;
            this->_array = new (std::nothrow) T[n];
            if (!(this->_array) && n != 0) {
                std::cout << "Error: Allocation fail" << std::endl;
                exit(EXIT_FAILURE);
            }
            return;
        }
        Array<T>(const Array<T> &src)
	    {
            std::cout << "Copy constructor called" << std::endl;
            this->_size = 0;
            *this = src;
        }
        ~Array<T>(void)
        {
            std::cout << "Destructor called" << std::endl;
            if (this->_size > 0)
                delete [] this->_array;
        }

        Array<T>	&operator=( const Array<T> &rhs )
        {
            std::cout << "Assignation overload called" << std::endl;
            if (this == &rhs)
                return *this;
            if (this->_size > 0)
                delete [] this->_array;
            this->_size = rhs.size();
            this->_array = new T[this->_size];
            if (!(this->_array) && this->_size != 0) {
                std::cout << "Error: Allocation fail" << std::endl;
                exit(EXIT_FAILURE);
            }
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = rhs[i];
            return *this;
        }
        T			&operator[](const int index) const
        {
            if (index < 0 || static_cast<unsigned int>(index) >= this->_size)
                throw std::overflow_error("Index out of bounds");
            return this->_array[index];
        }

        const unsigned int			&size( void ) const
        {
            return this->_size;
        }
    
    private :
        unsigned int    _size;
        T               *_array;

};



#endif