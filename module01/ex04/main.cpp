/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:31:22 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 18:13:42 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int err_msg()
{
    std::cout << "fail" << std::endl;
    return 1;
}

int main(int argc, char **argv)
{
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    size_t num = 0;
    std::string line;

    if (argc != 4 || s2.find(s1) != std::string::npos || s1 == "")
        return (err_msg());
    std::ifstream ifs(filename);
    if (ifs.fail() || strlen(argv[1]) < 1)
        return (err_msg());

    std::ofstream ofs(filename + ".replace");
    if (ofs.fail())
        return (err_msg());

    while (std::getline(ifs, line))
    {
        num = line.find(s1);
        while (num != std::string::npos)
        {
            line.erase(num, s1.size());
            line.insert(num, s2);
            num = line.find(s1);
        }
        ofs << line << std::endl;
    }
    return 0;
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q out");
// }
