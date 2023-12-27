/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:14:52 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/27 19:37:53 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "\033[36m[ DEBUG ]\033[0m" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "\033[32m[ INFO ]\033[0m" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "\033[33m[ WARNING ]\033[0m" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "\033[31m[ ERROR ]\033[0m" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*FuncPtrArray[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    std::string allLevel = "DEBUG,INFO,WARNING,ERROR";
    switch (allLevel.find(level))
    {
    case 0:
        (this->*FuncPtrArray[0])();
        break;
    case 6:
        (this->*FuncPtrArray[1])();
        break;
    case 11:
        (this->*FuncPtrArray[2])();
        break;
    case 19:
        (this->*FuncPtrArray[3])();
        break;
    default:
        break;
    }
}