/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:17:45 by igeorge           #+#    #+#             */
/*   Updated: 2022/11/23 16:17:45 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <fstream>

std::string replace(std::string old_string, std::string old_word, std::string new_word) {
    std::string new_string;
    int      start(0);
    int      pos;

    while ((pos = old_string.find(old_word, start))) {
        if (pos == (int)std::string::npos)
            break ;
        //std::cout << pos << std::endl;
        new_string.append(old_string, start, pos - start);
        new_string += new_word;
        start = pos + old_word.size();
    }
    new_string.append(old_string, start);
    return new_string;
}

/*c_str() Returns a pointer to an array that contains a null-terminated sequence of characters */
int    put_infile(std::string filename, std::string new_string) {
    std::ofstream   ofs(filename.c_str());

    ofs << new_string;
    ofs.close();
    return (0);
}

/* std::noskipws don't skip whitespaces */
int main(int argc, char **argv) {
    std::ifstream   ifs(argv[1]);
    std::string     old_string, new_string;
    std::string     filename(argv[1]);
    char            c;
    
    if (argc != 4) {
        std::cout << "Usage: <file> old_word new_word" << std::endl;
        return (1);
    }
    /*ifs.open(argv[1]);
    if (ifs.fail()) {
        std::cout << "Error : no such file or directory" << std::endl;
        return (1);
    }*/
    while (!ifs.eof() && ifs >> std::noskipws >> c) {
        old_string += c;
    }
    ifs.close();
    new_string = replace(old_string, argv[2], argv[3]);
    filename = filename + ".replace";
    if (put_infile(filename, new_string)) {
        std::cout << "Error: open file" << std::endl;
        return (1);
    }
    std::cout << argv[2] << " was replaced by " << argv[3] << " in " << filename << std::endl;
    return (0);
}
