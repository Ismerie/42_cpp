/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:19:28 by igeorge           #+#    #+#             */
/*   Updated: 2022/10/26 17:19:28 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H

# define PHONEBOOK_H

# include <iostream>
# include <string>
#include "Contact.hpp"

class   PhoneBook {
public :
	PhoneBook(void);
	~PhoneBook(void);

    void     	add_contact(void);
	void		search_contact(void);
	void		put_tab_contact(void);
	void		put_details_contact(int index, std::string name);

private :
	Contact _contacts[8];
	int		_index;
};

#endif
