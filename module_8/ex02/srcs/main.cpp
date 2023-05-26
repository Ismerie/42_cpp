/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:20:03 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/19 19:20:03 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main() {

    MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl << std::endl;
	mstack.pop();
	std::cout << "size = " << mstack.size() << std::endl << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
    std::cout << std::endl << std::endl;
	
    std::cout << "----------Copy Mutant-------------" << std::endl;
    MutantStack<int> s(mstack);
	std::cout << "size = " << s.size() << std::endl << std::endl;
	MutantStack<int>::reverse_iterator s_it = s.rbegin();
	MutantStack<int>::reverse_iterator s_ite = s.rend();
	++s_it;
	--s_it;
	while (s_it != s_ite)
	{
		std::cout << *s_it << std::endl;
		++s_it;
	}

    return 0;
}