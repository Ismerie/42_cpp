/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:59:48 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 14:59:48 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
public :
    Weapon(std::string type);
    ~Weapon(void);
    std::string getType(void) const;
    void        setType(std::string new_type);


private :
    std::string _type;
};

#endif