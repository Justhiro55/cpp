/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:58:09 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/12/26 17:00:30 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_nbAccounts++;
    this->_totalAmount = _totalAmount + initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";ammout:" << _amount
              << ";created" << std::endl;
}

Account::Account()
{
    this->_accountIndex = _nbAccounts;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount = 0;
    this->_nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _nbAccounts
              << ";ammout:" << _totalAmount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    _nbAccounts--;
    _totalAmount = _totalAmount - _amount;
    _totalNbDeposits = _totalNbDeposits - _nbDeposits;
    _totalNbWithdrawals = _totalNbWithdrawals - _nbWithdrawals;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

int Account::checkAmount(void) const
{
    if (_amount < 0)
        return 0;
    else
        return 1;
}

void Account::makeDeposit(int deposit)
{
    _amount = _amount + deposit;
    _totalAmount = _totalAmount + deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount - deposit
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawal:" << getNbWithdrawals()
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    bool result;

    _amount = _amount - withdrawal;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount + withdrawal;
    if (checkAmount() == 0)
    {
        result = true;
        _totalAmount = _totalAmount - withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal
                  << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals
                  << std::endl;
    }
    else
    {
        result = false;
        _amount = _amount + withdrawal;
        std::cout << ";withdrawal:refused"
                  << std::endl;
    }
    return (result);
}

void Account::_displayTimestamp(void)
{
    time_t ts;
    char buf[16];

    time(&ts);
    strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&ts));
    std::cout << "[" << buf << "]";
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}
