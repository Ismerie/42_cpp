/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:33:42 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/02 15:33:42 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConversion.hpp"

ScalarConversion::ScalarConversion(char *str) : _str(str), _value_int(0), 
_value_float(0), _value_double(0), _value_char(0) {
    int i = 0;

    this->_string = this->_str;
    if (this->parse())
        throw (ScalarConversion::BadArgumentException());
    if (!is_pseudoliterals()) {
        if (this->parse_convert())
            throw (ScalarConversion::BadArgumentException());
    }
    for (i = 0; i < 4; i++) {
        this->_invalid[i] = 0;
    }
    return ;
}

ScalarConversion::ScalarConversion() {
    return ;
}

ScalarConversion::ScalarConversion(const ScalarConversion &src) {
    *this = src;
    return ;
}

ScalarConversion::~ScalarConversion() {
    return ;
}

ScalarConversion    &ScalarConversion::operator=(ScalarConversion const &src) {
    this->_string = src.getString();
    this->_str = src.getStr();
    this->_type = src.getType();
    this->_value_int = src.getValueInt();
    this->_value_float = src.getValueFloat();
    this->_value_double = src.getValueDouble();
    this->_value_char = src.getValueChar();
    for(int i = 0; i < 4; i++) {
        this->_invalid[0] = src.getInvalid(i);
    }
    return *this;
}

// Functions

bool ScalarConversion::is_pseudoliterals() const {
    if (this->_string == "nan" || this->_string == "-inf" || this->_string == "+inf")
        return 1;
    else if (this->_string == "nanf" || this->_string == "-inff" || this->_string == "+inff")
        return 1;
    return 0;
}

int ScalarConversion::pseudoliterals() {
    if (this->_string == "nan" || this->_string == "-inf" || this->_string == "+inf") {
        this->_type = TypeDouble;
        this->_value_double = std::strtold(this->_str, NULL);
        return 1;
    }
    else if (this->_string == "nanf" || this->_string == "-inff" || this->_string == "+inff") {
        this->_type = TypeFloat;
        this->_value_float = std::atof(this->_str);
        return 1;
    }
    return 0;
}

bool ScalarConversion::parse_convert() {
    if (this->_type == TypeInt) {
        long lvalue;

        lvalue = std::atol(this->_str);
        if ((lvalue > std::numeric_limits<int>::max()) || (lvalue < std::numeric_limits<int>::min()))
            return 1;
        this->_value_int = lvalue;
    }
    else if (this->_type == TypeFloat) {
        double dvalue;

        dvalue = std::atof(this->_str);
        if ((dvalue > std::numeric_limits<float>::max()) || (dvalue < -std::numeric_limits<float>::max()))
            return 1;
        this->_value_float = dvalue;
    }
    else if (this->_type == TypeDouble) {
        long double ldvalue;

        ldvalue = std::strtold(this->_str, NULL);
        if ((ldvalue > std::numeric_limits<double>::max()) || (ldvalue < -std::numeric_limits<double>::max()))
            return 1;
        this->_value_double = ldvalue;
    }
    return 0;
}

bool    ScalarConversion::parse() {
    int length = strlen(this->_str);
    int i = 0;
    int point = 0;
    int f = 0;

    if (pseudoliterals())
        return 0;
    if (length == 1 && !std::isdigit(this->_str[0])) {
        this->_type = TypeChar;
        this->_value_char = this->_str[0];
        return 0;
    }
    this->_type = TypeInt;
     if (this->_str[0] == '-' || this->_str[0] == '+')
            i++;
    while (this->_str[i]) {
        if (!std::isdigit(this->_str[i]) && this->_str[i] != '.' && this->_str[i] != 'f')
            return 1;
        if (this->_str[i] == '.') {
            if (i != 0 && (i != length - 1) && point == 0) {
                this->_type = TypeDouble;
                point++;
            }
            else
                return 1;
        }
        else if (this->_str[i] == 'f') {
            if (i == (length - 1) && std::isdigit(this->_str[i - 1]) && this->_type == TypeDouble
                && f == 0) {
                this->_type = TypeFloat;
                f++;
            }
            else
                return 1;
        }
        i++;
    } 
    return 0;
}

void    ScalarConversion::convert() {
    switch (this->_type) {
        case 0:
            convertFromChar();
            break;
        case 1:
            convertFromInt();
            break;
        case 2:
            convertFromFloat();
            break;
        case 3:
            convertFromDouble();
            break;
        default:
            throw (ScalarConversion::BadArgumentException());
            break;
    }
    return;
}

void    ScalarConversion::convertFromChar() {
    this->_value_int = static_cast<int>(this->_value_char);
    this->_value_float = static_cast<float>(this->_value_char);
    this->_value_double = static_cast<double>(this->_value_char);
    return ;
}

void    ScalarConversion::convertFromInt() {
    if (is_pseudoliterals() || this->_value_int > 127
        || this->_value_int < 0)
            this->_invalid[0] = 1;
    else if (!std::isprint(this->_value_int))
            this->_invalid[0] = 2;
    else
        this->_value_char = static_cast<char>(this->_value_int);
    this->_value_float = static_cast<float>(this->_value_int);
    this->_value_double =static_cast<double>(this->_value_int);
    return ;
}

void    ScalarConversion::convertFromFloat() {
    if (is_pseudoliterals() || this->_value_float > 127
        || this->_value_float < 0)
            this->_invalid[0] = 1;
    else if (!std::isprint(this->_value_float))
            this->_invalid[0] = 2;
    else
        this->_value_char = static_cast<char>(this->_value_float);
    if (is_pseudoliterals() || this->_value_float > std::numeric_limits<int>::max()
        || this->_value_float < std::numeric_limits<int>::min())
        this->_invalid[1] = 1;
    else
        this->_value_int = static_cast<int>(this->_value_float);
    this->_value_double =static_cast<double>(this->_value_float);
}

void    ScalarConversion::convertFromDouble() {
    if (is_pseudoliterals() || this->_value_double > 127
        || this->_value_double < 0)
            this->_invalid[0] = 1;
    else if (!std::isprint(this->_value_double))
            this->_invalid[0] = 2;
    else
         this->_value_char = static_cast<char>(this->_value_double);
    if (is_pseudoliterals() || this->_value_double > std::numeric_limits<int>::max()
        || this->_value_double < std::numeric_limits<int>::min())
        this->_invalid[1] = 1;
    else
        this->_value_int = static_cast<int>(this->_value_double);
    if ((this->_value_double > std::numeric_limits<float>::max()
        || this->_value_double < -std::numeric_limits<float>::max()) && !is_pseudoliterals())
        this->_invalid[2] = 1;
    else
        this->_value_float = static_cast<float>(this->_value_double);
    return ;
}

//Getters
int    ScalarConversion::getInvalid(int index) const {
    return (this->_invalid[index]);
}

char    ScalarConversion::getValueChar() const {
    return (this->_value_char);
}

int    ScalarConversion::getValueInt() const {
    return (this->_value_int);
}

float    ScalarConversion::getValueFloat() const {
    return (this->_value_float);
}

double    ScalarConversion::getValueDouble() const {
    return (this->_value_double);
}

char    *ScalarConversion::getStr() const {
    return (this->_str);
}

std::string ScalarConversion::getString() const {
    return (this->_string);
}

int    ScalarConversion::getType() const {
    return (this->_type);
}

std::ostream &operator<<(std::ostream &out, const ScalarConversion &src)
{
    if (src.getInvalid(0) == 1)
        out << "char: impossible" << std::endl;
    else if (src.getInvalid(0) == 2)
        out << "char: Non displayable" << std::endl;
    else
       out << "char: " << src.getValueChar() << std::endl;
    
    if (src.getInvalid(1))
        out << "int: impossible" << std::endl;
    else
       out << "int: " << src.getValueInt() << std::endl;
    
    if (src.getInvalid(2) == 1)
        out << "float: impossible" << std::endl;
    else if (src.is_pseudoliterals())
        out << "float: " << src.getValueFloat() << "f" << std::endl;
    else if (src.getValueFloat() >= 1000000)
        out << "float: " << src.getValueFloat() << "f" << std::endl;
    else
        out << "float: " << src.getValueFloat() << ".0f" << std::endl;
    
    if (src.getInvalid(3) == 1)
        out << "double: impossible";
    else if (src.is_pseudoliterals() || src.getValueDouble() >= 1000000)
        out << "double: " << src.getValueDouble();
    else
       out << "double: " << src.getValueDouble() << ".0";
    return (out);
}
