/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:13:25 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/18 16:13:25 by igeorge          ###   ########.fr       */
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
    Animal	*meta[10];
    Brain           *brain;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

//THIS PART IS FOR TESTING DEEP COPY ↓
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	brain = meta[7]->getBrain();
	brain->setIdeas(0, "I'm hungry");
    brain->setIdeas(1, "That's a strange idea I'm having");
    brain->setIdeas(2, "Ball!!!!!");
    brain->setIdeas(3, "Squirrel!!!!!");
	std::cout << meta[7]->getBrain()->getIdeas(0) << std::endl;

	*(meta[5]) = *(meta[7]);
	std::cout << meta[5]->getBrain()->getIdeas(2) << std::endl;

	for (int i = 0; i < 10; i++)
		delete meta[i];

	return (0);
}
