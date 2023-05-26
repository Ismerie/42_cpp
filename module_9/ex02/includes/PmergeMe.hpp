/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:29:11 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/17 18:29:11 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe {
    public :
        PmergeMe(void);
        PmergeMe(const PmergeMe &src);
        ~PmergeMe(void);

        PmergeMe &operator=(const PmergeMe &other);

        const std::vector<long long>	&getVector(void) const;
		const std::deque<long long>		&getDeque(void) const;
        void                            setDeque(char **input);
        
    //    std::deque<long long>           mergeDeque();
        std::deque<long long>           mergeDeque(std::deque<long long>& left, std::deque<long long>& right);
        std::deque<long long>           sortDeque(std::deque<long long>& vec);
        void                            sortDeq(int argc, char **argv);
        
        std::vector<long long>          mergeVector(std::vector<long long>& left, std::vector<long long>& right);
        std::vector<long long>          sortVector(std::vector<long long>& vec);
        void                            sortVec(int argc, char **argv);
        
        bool                            checkInput(char **input);


    private :
        std::deque<long long>   _mydeque;
        std::vector<long long>  _myvector;
};

#endif