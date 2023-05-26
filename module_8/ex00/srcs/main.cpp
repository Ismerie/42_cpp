/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:32:15 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/17 19:32:15 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main() {
    std::cout << "----------Container Deque-------------" << std::endl;
    {
        std::deque<int>			vect;
        std::deque<int>::iterator	it;

        vect.push_back(5);
        vect.push_back(45);
        vect.push_back(22);
        vect.push_back(19);
        
        it = easyfind(vect, 45);
        if (it == vect.end())
            std::cout << "iterator reached the end of container" << std::endl;
        else
            std::cout << "iterator : " << *it << std::endl;
        it = easyfind(vect, 42);
        if (it == vect.end())
            std::cout << "iterator reached the end of container" << std::endl << std::endl;
        else
            std::cout << "iterator :" << *it << std::endl << std::endl;
    }


    std::cout << "----------Container Vector-------------" << std::endl;
    {
        std::vector<int>			vect;
        std::vector<int>::iterator	it;

        vect.push_back(5);
        vect.push_back(45);
        vect.push_back(22);
        vect.push_back(19);
        
        it = easyfind(vect, 45);
        if (it == vect.end())
            std::cout << "iterator reached the end of container" << std::endl;
        else
            std::cout << "iterator : " << *it << std::endl;
        it = easyfind(vect, 42);
        if (it == vect.end())
            std::cout << "iterator reached the end of container" << std::endl << std::endl;
        else
            std::cout << "iterator :" << *it << std::endl << std::endl;
    }


     std::cout << "----------Container List-------------" << std::endl;
    {
        std::list<int>			vect;
        std::list<int>::iterator	it;

        vect.push_back(5);
        vect.push_back(45);
        vect.push_back(22);
        vect.push_back(19);
        
        it = easyfind(vect, 45);
        if (it == vect.end())
            std::cout << "iterator reached the end of container" << std::endl;
        else
            std::cout << "iterator : " << *it << std::endl;
        it = easyfind(vect, 42);
        if (it == vect.end())
            std::cout << "iterator reached the end of container" << std::endl << std::endl;
        else
            std::cout << "iterator :" << *it << std::endl;
    }
    return 0;
}
