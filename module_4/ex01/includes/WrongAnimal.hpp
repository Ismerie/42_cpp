/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:36:09 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/03 12:36:09 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>
# include <string>

class   WrongAnimal {
    public :
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &src);
        virtual ~WrongAnimal(void);
    
        WrongAnimal    &operator=(const WrongAnimal &other);

        virtual void    makeSound(void) const;
        std::string     getType(void) const;

    protected :
        std::string          _type;

};

#endif
