/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:14 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/11 16:29:14 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange {
    public :
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange(void);

        BitcoinExchange &operator=(const BitcoinExchange &other)
        
        void    exchangeFile(char *name_file);
    
    private :
        std::map<std::string, float>    _data;
        std::ifstream                   _file;
        std::string                     _date;
        int                             _year;
        int                             _month;
        int                             _day;
        float                           _value;

        void    checkFile(char *name_file);
        int     parseLine(std::string line);
        int     checkDate(void);
        void    displayData(void) const;
};

#endif