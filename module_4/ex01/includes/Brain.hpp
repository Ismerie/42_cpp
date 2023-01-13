/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:16:25 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/03 13:16:25 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>

class   Brain {
    public :
        Brain(void);
        Brain(const Brain &src);
        virtual ~Brain(void);
    
        Brain    &operator=(const Brain &other);

        std::string     getIdeas(size_t i) const;
        void            setIdeas(size_t i, std::string idea);

    private :
        std::string          _ideas[100];

};

#endif