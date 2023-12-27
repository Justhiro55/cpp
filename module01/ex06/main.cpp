/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:31:22 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 19:42:25 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    Harl h;
    std::string arg = argv[1];
    
    h.complain(arg);
    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q out");
// }
