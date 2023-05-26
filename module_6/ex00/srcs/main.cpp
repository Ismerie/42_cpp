/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:33:39 by igeorge           #+#    #+#             */
/*   Updated: 2023/02/02 15:33:39 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConversion.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Bad arguments" << std::endl;
        return (1);
    }
    try {
        ScalarConversion scalar(argv[1]);
        scalar.parse();
        scalar.convert();
        std::cout << scalar << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}