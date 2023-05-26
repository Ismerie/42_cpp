/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:25:05 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/13 20:25:05 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>

Base    *generate(void) {
    int r = rand() % 3;

	if (r == 0) {
		std::cout << "Test A :";
		return (new A);
	}
	else if (r == 1){
		std::cout << "Test B :";
		return (new B);
	}
	else {
		std::cout << "Test C :";
		return (new C);
	}
}

void    identify(Base *p) {
    if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
    return ;
}

void    identify(Base &p) {
   try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
    return ;
}

int main() {
    srand(time(NULL));

	for (int i = 0; i < 50; i++)
	{
		Base *o = generate();
		identify(o);
		std::cout << ", ";
		identify(*o);
		delete o;
	}
    return 0;
}
