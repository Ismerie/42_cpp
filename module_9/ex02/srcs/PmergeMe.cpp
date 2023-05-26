/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:30:26 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/17 18:30:26 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    return ;
}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
    return ;
}

PmergeMe::~PmergeMe(void) {
    return ;
}

//A compléter
PmergeMe    &PmergeMe::operator=(const PmergeMe &src) {
    this->_mydeque = src._mydeque;
    this->_myvector = src._myvector;
    return (*this);
}

const std::deque<long long>	&PmergeMe::getDeque(void) const
{
	return (this->_mydeque);
}

const std::vector<long long>	&PmergeMe::getVector(void) const
{
	return (this->_myvector);
}


void    PmergeMe::setDeque(char **input) {
    for (int i = 0; input[i]; i++)
        _mydeque.push_back(atoll(input[i]));
}


std::vector<long long> PmergeMe::mergeVector(std::vector<long long>& left, std::vector<long long>& right) {
	std::vector<long long> result;

    // Merge the two vectors until one of them becomes empty
    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    // Add any remaining elements from the left vector
    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    // Add any remaining elements from the right vector
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

std::vector<long long>    PmergeMe::sortVector(std::vector<long long>& vec) {
    if (vec.size() <= 1) {
		return vec;
	}
	
	// Divide the deque into two halves
	int mid = vec.size() / 2;
	std::vector<long long>	left(vec.begin(), vec.begin() + mid);
	std::vector<long long>	right(vec.begin() + mid, vec.end());
	
	
	// Recursively sort the left and right halves
	left = sortVector(left);
    right = sortVector(right);
	
	// Merge the sorted halves
	return (mergeVector(left, right));
}

void PmergeMe::sortVec(int argc, char **argv)
{
	std::vector<long long> storage;
	
	for (int i = 1; i < argc; i += 1) {
		storage.push_back(atoll(argv[i]));
	}
	
	_myvector = sortVector(storage);
	return ;

}





std::deque<long long> PmergeMe::mergeDeque(std::deque<long long>& left, std::deque<long long>& right) {
	std::deque<long long> result;

    // Merge the two deques until one of them becomes empty
    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    // Add any remaining elements from the left deque
    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    // Add any remaining elements from the right deque
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

std::deque<long long>    PmergeMe::sortDeque(std::deque<long long>& vec) {
    if (vec.size() <= 1) {
		return vec;
	}
	
	// Divide the deque into two halves
	int mid = vec.size() / 2;
	std::deque<long long>	left(vec.begin(), vec.begin() + mid);
	std::deque<long long>	right(vec.begin() + mid, vec.end());
	
	
	// Recursively sort the left and right halves
	left = sortDeque(left);
    right = sortDeque(right);
	
	// Merge the sorted halves
	return (mergeDeque(left, right));
}

void PmergeMe::sortDeq(int argc, char **argv)
{
	std::deque<long long> storage;
	
	for (int i = 1; i < argc; i += 1) {
		storage.push_back(atoll(argv[i]));
	}
	
	_mydeque = sortDeque(storage);
	return ;

}

bool    PmergeMe::checkInput(char **input) {
    for (int i = 0; input[i]; i++) 
    {
        for (int j = 0; input[i][j]; j++) 
        {
            if (!isdigit(input[i][j]))
                return (false);
        }
    }
    return (true);
}