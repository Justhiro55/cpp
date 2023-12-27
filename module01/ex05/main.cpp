/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:31:22 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 18:26:24 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "Harl.hpp"

int main()
{
    Harl h;

    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");
    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q out");
// }
