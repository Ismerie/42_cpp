/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:21:56 by igeorge           #+#    #+#             */
/*   Updated: 2022/10/26 17:21:56 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CONTACT_H

# define CONTACT_H

# include <iostream>
# include <string>

class   Contact {
public :
    Contact(void);
    ~Contact(void);

    void        set_contact(void);
    std::string getdetails(int index) const;
    std::string getcontact_details(int index) const;
    void        setcontact_details(std::string details, int index);

private :
    static const std::string    _details[5];
    std::string                 _contact_details[5];
};

#endif
