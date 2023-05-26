/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:21:54 by igeorge           #+#    #+#             */
/*   Updated: 2023/04/17 15:21:54 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    RPN expression;
    if (!expression.displayProcess(argv[1]))
        return (1);
    return (0);
}