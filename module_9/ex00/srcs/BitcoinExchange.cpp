/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:12 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/11 16:29:12 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    std::ifstream           file;
    std::string             line;
    std::string             key;
    std::string             value;
    int                     nbr_line = 0;
    std::string::iterator   it;

    file.open("data.csv", std::ifstream::in);
    if (file.bad() || file.fail())
    {
        std::cerr << "Error: std::ifstream::open()" << std::endl;
        exit(EXIT_FAILURE);
    }
    while(std::getline(file, line))
    { 
        if (file.bad()) {
        std::cerr << "Error: std::getline()" << std::endl;
        file.close();
        exit(EXIT_FAILURE);
        }
        nbr_line++;
        if (nbr_line == 1)
          continue ;
        key = "";
        value = "";
        for (it = line.begin(); *it != ','; ++it)
			key += *it;
		for (it++; it != line.end(); ++it)
			value += *it;
        _data[key] = static_cast<float>(atof(value.c_str()));
    }
    file.close();
    return ;

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->data = src.data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
    return ;
}

void    BitcoinExchange::checkFile(char *name_file) {
    std::string     line;

    _file.open(name_file, std::ifstream::in);
    if (_file.bad() || _file.fail()) {
        std::cerr << "Error: std::ifstream::open()" << std::endl;
        throw std::exception();
    }
    std::getline(_file, line);
    if (_file.bad()) {
        std::cerr << "Error: std::getline()" << std::endl;
        _file.close();
        throw std::exception();
    }
    if (line != "date | value") {
        std::cerr << "Error: wrong file format" << std::endl;
        _file.close();
        throw std::exception();
    }
    return ;
}

int     BitcoinExchange::checkDate() {
    std::string::iterator           it;
    int                             i = -1;
    std::string                     year_str;
    std::string                     month_str;
    std::string                     day_str;

    it = _date.begin();
    while (++i < 4) {
        if (it == _date.end() || !isdigit(*it))
            return (0);
        year_str += *it;
        it++;
    }
    if (*it != '-')
        return (0);
    it++;
    while (++i < 7) {
        if (it == _date.end() || !isdigit(*it))
            return (0);
        month_str += *it;
        it++;
    }
    if (*it != '-')
        return (0);
    it++;
    while (++i < 10) {
        if (it == _date.end() || !isdigit(*it))
            return (0);
        day_str += *it;
        it++;
    }
    if (it != _date.end())
        return (0);
    _year = atof(year_str.c_str());
    _month = atof(month_str.c_str());
    _day = atof(day_str.c_str());
    if (_year < 2009 || _month < 1 || _month > 12 || _day < 1 || _day > 31)
        return (0);
    if (_year == 2009 && _month == 1 && _day < 2)
        return (0);
    if (_day == 31 && (_month != 1 && _month != 3 && _month != 5 && _month != 7
        && _month != 8 && _month != 11 && _month != 12))
        return (0);
    if (_month == 2 && (_day == 30 || _day == 31))
        return (0);
    if (_month == 2 && _day == 29 && (_year % 4 != 0 || _year % 100 != 0 || _year % 400 != 0))
        return (0);
    return (1);
}

int    BitcoinExchange::parseLine(std::string line) {
    std::string::iterator   it;
    int                     point = 0;
    std::string             value_string;

    _date = "";
    value_string = "";
    for (it = line.begin(); *it != ' '; ++it) {
        if (it == line.end()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            return (0);
        }
        _date += *it;
    }
    if (!checkDate()) {
        std::cerr << "Error: bad input => " << line << std::endl;
            return (0);
    }
    for (int i = 0; i != 3  && it != line.end(); ++it) {
        if ((i == 0 || i == 2) && *it != ' ') {
           std::cerr << "Error: bad input => " << line << std::endl;
           return (0);
        }
        if (i == 1 && *it != '|') {
           std::cerr << "Error: bad input => " << line << std::endl;
           return (0);
        }
        i++;
    }
    if (it == line.end()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            return (0);
        }
    for (int i = 0; it != line.end(); ++it) {
        if (i == 0 && *it == '-') {
            std::cerr << "Error: not a positive number. " << std::endl;
            return (0);
        }
        if (i == 0 && *it == '.') {
            std::cerr << "Error: bad input => " << line << std::endl;
            return (0);
        }
        if (*it == '.' && point == 1) {
            std::cerr << "Error: bad input => " << line << std::endl;
            return (0);
        }
        else if (*it == '.') {
            value_string += *it;
            point++;
        }
        else if (isdigit(*it))
            value_string += *it;
        else {
            std::cerr << "Error: bad input => " << line << std::endl;
            return (0);
        }
        i++;
    }
    _value = static_cast<float>(atof(value_string.c_str()));
    if (_value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
            return (0);
    }
    return (1);
}

void	BitcoinExchange::displayData(void) const
{
	std::map<std::string, float>::const_iterator	it = this->_data.begin();

	while (it != this->_data.end() && _year > atoi(it->first.substr(0, 4).c_str()))
		it++;
	if (it == this->_data.end() || _month < atoi(it->first.substr(5, 2).c_str()))
	{
		it--;
		std::cout << _date << " => " << _value << " = " << _value * it->second <<
			std::endl;
		return ;
	}
	while (it != this->_data.end() && _month > atoi(it->first.substr(5, 2).c_str()))
		it++;
	if (it == this->_data.end() || _day < atoi(it->first.substr(8, 2).c_str()))
	{
		it--;
		std::cout << _date << " => " << _value << " = " << _value * it->second <<
			std::endl;
		return ;
	}
	while (it != this->_data.end() && _day > atoi(it->first.substr(8, 2).c_str()))
		it++;
	if (it == this->_data.end() || _day < atoi(it->first.substr(8, 2).c_str()))
		it--;
	std::cout << _date << " => " << _value << " = " << _value * it->second <<
		std::endl;
    return ;
}

void    BitcoinExchange::exchangeFile(char *name_file) {
    std::string line;
    
    checkFile(name_file);
    while(std::getline(_file, line))
    { 
        if (_file.bad()) {
            std::cerr << "Error: std::getline()" << std::endl;
            _file.close();
            exit(EXIT_FAILURE);
        }
        if (!parseLine(line))
            continue ;
        displayData();
    }
    _file.close();
    return ;
}

