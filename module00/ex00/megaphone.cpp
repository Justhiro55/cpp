/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:57:11 by hhagiwar          #+#    #+#             */
/*   Updated: 2024/01/22 20:32:21 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2 || (argv[1] && argv[1][0] == '\0'))
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.size(); j++)
			{
				std::cout << char(std::toupper(str[j]));
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}
