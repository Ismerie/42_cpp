/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:01:15 by igeorge           #+#    #+#             */
/*   Updated: 2022/10/26 20:01:15 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"

const std::string    Contact::_details[5] = {
    "First name",
    "Last name",
    "Nickname",
    "Phone number",
    "Darkest secret",
};

Contact::Contact(void) {
    return;
}

Contact::~Contact(void) {
    return;
}

std::string  Contact::getdetails(int index) const {
    return this->_details[index];
}

std::string  Contact::getcontact_details(int index) const {
    return this->_contact_details[index];
}

void  Contact::setcontact_details(std::string details, int index) {
    this->_contact_details[index] = details;
    return ;
}
