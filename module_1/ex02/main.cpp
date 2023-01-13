/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:25:19 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/04 14:25:19 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main(void) {
    std::string     brain("HI THIS IS BRAIN");
    std::string    *brainPtr = &brain;
    std::string    &brainRef = brain;

    std::cout << "Address brain : " << &brain << std::endl;
    std::cout << "Address brainPtr : " << brainPtr << std::endl;
    std::cout << "Address brainRef : " << &brainRef << std::endl;
    std::cout << std::endl;
    std::cout << "Value brain : " << brain << std::endl;
    std::cout << "Value brainPtr : " << *brainPtr << std::endl;
    std::cout << "Value brainRef : " << brainRef << std::endl;
    return(0);
}