/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:57:12 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/14 17:57:12 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file" << std::endl; 
        return (EXIT_FAILURE);
    }

    BitcoinExchange my_bitcoins;
    
    try {
        my_bitcoins.exchangeFile(argv[1]);
    }
    catch (std::exception &e) {
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}