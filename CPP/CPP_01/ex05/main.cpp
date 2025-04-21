/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/09 20:35:27 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main() {
    Harl harl;
    
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    harl.complain("INFO");
    std::cout << std::endl;

    harl.complain("WARNING");
    std::cout << std::endl;

    harl.complain("ERROR");
    std::cout << std::endl;

    harl.complain("WRONG");
    
    return 0;
}