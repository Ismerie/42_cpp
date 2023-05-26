/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:08:50 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/13 20:08:50 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"
#include <iostream>
#include <stdint.h>

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main( void )
{
	Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t	raw;

	ptr->data = "Hi, how's going";
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "ptr->data = " << ptr->data << std::endl << std::endl;
	
	std::cout << "--------Serialize------------" << std::endl;
	raw = serialize(ptr);
	std::cout << "serialize ptr = " << raw << std::endl << std::endl;
	
	std::cout << "----------Deserialize---------" << std::endl;
	new_ptr = deserialize(raw);
	std::cout << "deserialize ptr = " << new_ptr << std::endl;
	std::cout << "new_ptr->data = " << new_ptr->data << std::endl;

    delete ptr;
}