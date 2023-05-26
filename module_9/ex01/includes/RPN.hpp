/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:23:14 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/17 15:23:14 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN {
    public :
        RPN(void);
        RPN(const RPN &src);
        ~RPN(void);

        RPN &operator=(const RPN &other);
        int    displayProcess(std::string expression);

    private :
        std::stack<long long> _mystack;

        void    resolveExpression(char symbol);

        
};

#endif