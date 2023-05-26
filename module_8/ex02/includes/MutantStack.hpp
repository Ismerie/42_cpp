/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:20:55 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/19 19:20:55 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
    public:

        MutantStack<T>( void ) : std::stack<T>(){ 
            return;
        }
        MutantStack<T>( const MutantStack<T> &src ) : std::stack<T>(src) { 
            *this = src;
            return ;
        }
        ~MutantStack<T>( void ) {
            return;
        }

        MutantStack<T>	&operator=( const MutantStack<T> &rhs ) {
            std::stack<T>::operator=(rhs);
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

        iterator	begin( void ) {
            return this->c.begin();
        }
        iterator	end( void ) {
            return this->c.end();
        }
        reverse_iterator	rbegin( void ) {
            return this->c.rbegin();
        }
        reverse_iterator	rend( void ) {
            return this->c.rend();
        }
};


#endif