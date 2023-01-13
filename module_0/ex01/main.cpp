/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:07:07 by igeorge           #+#    #+#             */
/*   Updated: 2022/10/26 17:07:07 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook   phonebook;
    Contact     contact;
    std::string command;

    while (command != "EXIT")
    {
        std::cout << "Do you want to SEARCH, ADD a contact or EXIT ?" << std::endl;
        std::getline(std::cin, command);
        if (command == "ADD") {
            std::cout << std::endl << "# Please complete the new contact's personal details" << std::endl;
            phonebook.add_contact();
            std::cout << "# Contact added #" << std::endl << std::endl;
            continue ;
        }
        else if (command == "SEARCH") {
            phonebook.search_contact();
            continue ;
        }
    }
    return(0);
}
