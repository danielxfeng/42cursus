#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    ++_nbAccounts;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    ++_nbDeposits;
    _totalAmount += deposit;
    ++_totalNbDeposits;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    // [19920104_091532] index:5;p_amount:23;withdrawal:refused
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    ++_nbWithdrawals;
    _totalAmount -= withdrawal;
    ++_totalNbWithdrawals;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int		Account::checkAmount( void ) const {
    return _amount;
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void	Account::_displayTimestamp( void ) {
    auto ts = time(NULL);
    auto datetime = *localtime(&ts);
    char output[20];
    strftime(output, 50, "[%Y%m%d_%H%M%S] ", &datetime);
    std::cout << output;
}