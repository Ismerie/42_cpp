/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:31:09 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/06 16:31:09 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"

int main()
{
	Animal	*tab_animal[4];
	Dog		*dog = new Dog();
	Cat		*cat = new Cat();

	dog->getBrain()->setIdeas(0, "I'm hungry");;
	cat->getBrain()->setIdeas(0, "I'm tired");
	tab_animal[0] = new Dog(*dog);
	tab_animal[2] = new Cat(*cat);
	tab_animal[1] = dog;
	tab_animal[3] = cat;
	tab_animal[1]->getBrain()->setIdeas(0, "Ball !!!");
	tab_animal[3]->getBrain()->setIdeas(0, "Squirrel !!!");
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << tab_animal[i]->getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete tab_animal[i];
	return 0;
}
