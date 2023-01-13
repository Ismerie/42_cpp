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

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
    std::cout << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* c = new WrongCat();
    c->makeSound();
    wrong->makeSound();
    delete c;
    delete wrong;
    return 0;
}
