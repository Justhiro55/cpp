/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:31:22 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 15:29:05 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string stringREF = str;

    std::cout << "\033[36mThe memory address\033[0m" << std::endl;
    std::cout << "strinf variable:  " << &str << std::endl;
    std::cout << "stringPTR:        " << stringPTR << std::endl;
    std::cout << "stringREF:        " << &stringREF << std::endl;

    std::cout << std::endl;
    std::cout << "\033[36mThe value\033[0m" << std::endl;
    std::cout << "string variable:  " << str << std::endl;
    std::cout << "stringPTR:        " << *stringPTR << std::endl;
    std::cout << "stringREF:        " << stringREF << std::endl;
    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q out");
// }
