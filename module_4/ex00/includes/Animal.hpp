/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:15:48 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/18 16:15:48 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class   Animal {
    public :
        Animal(void);
        Animal(const Animal &src);
        virtual ~Animal(void);
    
        Animal    &operator=(const Animal &other);

        virtual void    makeSound(void) const;
        std::string     getType(void) const;

    protected :
        std::string          _type;

};

#endif
