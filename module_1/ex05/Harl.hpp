/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:12:23 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/27 13:12:23 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
    public :
        Harl(void);
        ~Harl(void);
        void    complain(std::string level);

     private :
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};

#endif