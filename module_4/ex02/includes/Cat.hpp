/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:51:37 by igeorge           #+#    #+#             */
/*   Updated: 2022/12/18 16:51:37 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class   Cat : public Animal {
    public :
        Cat(void);
        Cat(const Cat &src);
        virtual ~Cat(void);
    
        Cat    &operator=(const Cat &other);

        virtual void    makeSound(void) const;
        Brain           *getBrain(void) const;
    
    private : 
        Brain *_brain;

};

#endif