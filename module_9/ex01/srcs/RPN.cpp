/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:22:51 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/17 15:22:51 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN(void) {
    return ;
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN(void) {
    return ;
}

RPN	&RPN::operator=(const RPN &src)
{
	this->_mystack = src._mystack;
	return (*this);
}


void RPN::resolveExpression(char symbol) {
    long long   nbr1;
    long long   nbr2;

    nbr2 = _mystack.top();
    _mystack.pop();
    nbr1 = _mystack.top();
    _mystack.pop();
    if (symbol == '+')
        _mystack.push(nbr1 + nbr2);
    else if (symbol == '-')
        _mystack.push(nbr1 - nbr2);
    else if (symbol == '*')
        _mystack.push(nbr1 * nbr2);
    else if (symbol == '/')
        _mystack.push(nbr1 / nbr2);
    return ;
}


int RPN::displayProcess(std::string expression) {
    std::string::iterator   it;

    for (it = expression.begin(); it != expression.end(); ++it) {
        if (isdigit(*it))
            _mystack.push(*it - 48);
        else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') {
            if (_mystack.size() < 2) {
                std::cerr << "Error: expression" << std::endl;
                return (0);
            }
            resolveExpression(*it);
        }
        else if (*it == ' ')
            continue ;
        else {
            std::cerr << "Error" << std::endl;
            return (0);
        }
    }
    if (_mystack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return (0);
    } 
    std::cout << _mystack.top() << std::endl;
    return (1);
}
