/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:21:30 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/18 16:21:30 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class   Dog : public Animal {
    public :
        Dog(void);
        Dog(const Dog &src);
        virtual ~Dog(void);
    
        Dog    &operator=(const Dog &other);

        virtual void    makeSound(void) const;
        Brain           *getBrain(void) const;

    private : 
        Brain *_brain;
};

#endif