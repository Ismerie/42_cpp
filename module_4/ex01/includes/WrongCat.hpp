/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:41:09 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/03 12:41:09 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal {
    public :
        WrongCat(void);
        WrongCat(const WrongCat &src);
        virtual ~WrongCat(void);
    
        WrongCat    &operator=(const WrongCat &other);

        virtual void    makeSound(void) const;

};

#endif