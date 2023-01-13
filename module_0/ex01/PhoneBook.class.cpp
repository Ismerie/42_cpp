/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:44:22 by igeorge           #+#    #+#             */
/*   Updated: 2022/10/26 17:44:22 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) : _index(0) {
    return;
}

PhoneBook::~PhoneBook(void) {
    return;
}

void    PhoneBook::add_contact(void) {
    int         i;
    size_t      lenght;
    std::string details;

    for (i = 0; i < 5; i++) {
        std::cout << this->_contacts[this->_index].getdetails(i) << " : ";
        std::getline(std::cin, details);
        lenght = details.size();
        if (lenght == 0) {
            std::cout << "# An entry cannot be empty" << std::endl << std::endl;
            i = i - 1;
        }
        else
            this->_contacts[this->_index].setcontact_details(details, i);
    }
    if (this->_index == 7)
        this->_index = 0;
    else
        this->_index++;
    return ;
}

void    PhoneBook::put_tab_contact(void) {
    int         i_contact;
    int         i_details;
    int         nbr_space;
    std::string details;

    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|     Index|Fisrt name| Last name|  Nickname|" << std::endl;
    std::cout << " -------------------------------------------" << std::endl;
    for (i_contact = 0; i_contact < 8; i_contact++) {
         std::cout << "|         " << i_contact + 1 << "|";
        for (i_details = 0; i_details < 3; i_details++) {
            details = this->_contacts[i_contact].getcontact_details(i_details);
            if (details.length() > 10) {
                details.resize(9);
                details.resize(10, '.');
                std::cout << details << '|';
            }
            else {
                for (nbr_space = 10 - details.length(); nbr_space > 0; nbr_space--)
                    std::cout << ' ';
                std::cout << details << '|';
            }

        }
        std::cout << std::endl << " -------------------------------------------" << std::endl;
    }
    return ;
}

void    PhoneBook::put_details_contact(int index, std::string name) {
    int i;

    std::cout  << name << "'s details" << std::endl;
    for (i = 0; i < 5; i++) {
        std::cout << this->_contacts[index].getdetails(i) << " : ";
        std::cout << this->_contacts[index].getcontact_details(i) << std::endl; 
    }
    std::cout << std::endl;
    return ;
}

void    PhoneBook::search_contact(void) {
    int         i(0);
    std::string tab_nbr[8] = {"1","2","3","4","5","6","7","8"};
    std::string index;
    std::string name;


    put_tab_contact();
    std::cout << "Which contact index do you want to see ?" << std::endl;
    std::getline(std::cin, index);
    std::cout << std::endl;
    while (i < 8) {
        if (index.compare(tab_nbr[i]) == 0)
            break ;
        else if (i == 7) {
            std::cout << "# The index must be between 1 and 8" << std::endl;
            std::cout << "Which contact index do you want to see ?" << std::endl;
            std::getline(std::cin, index);
            std::cout << std::endl;
            i = 0;
        }
        else
            i++;
    }
    name = this->_contacts[i].getcontact_details(0);
    if (name.length() == 0) {
         std::cout << "This contact is empty" << std::endl;
    }
    else 
        put_details_contact(i, name);
    return ;
}