/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:33:31 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/02 15:33:31 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <limits>

class   ScalarConversion {
    public :
        ScalarConversion(char *str);
        ScalarConversion();
        ScalarConversion(const ScalarConversion &src);
        virtual ~ScalarConversion();

        ScalarConversion &operator=(ScalarConversion const &src);

        bool    parse();
        void    convert();
        bool    parse_convert();
        bool    is_pseudoliterals() const;
        int     pseudoliterals();
        void    convertFromChar();
        void    convertFromInt();
        void    convertFromFloat();
        void    convertFromDouble();

        //Getters
        int     getInvalid(int index) const;
        char    getValueChar() const;
        int     getValueInt() const;
        float   getValueFloat() const;
        double  getValueDouble() const;
        std::string getString() const;
        char    *getStr() const;
        int     getType() const;

        
        class BadArgumentException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return ("Error: Bad argument exception");
                }
        };

    private :
        enum Type {
            TypeChar,
            TypeInt,
            TypeFloat,
            TypeDouble,
        };
        std::string     _string;
        char            *_str;
        int             _type;
        int             _invalid[4];
        int             _value_int;
        float           _value_float;
        double          _value_double;
        char            _value_char;


};

std::ostream &operator<<(std::ostream &out, const ScalarConversion &src);

#endif