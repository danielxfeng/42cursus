#pragma once
#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> db_;
    std::map<std::string, float> buildDb(std::string db_fn);

public:
    BitcoinExchange() = delete;
    BitcoinExchange(std::string db_filename);
    BitcoinExchange(const BitcoinExchange &o);
    BitcoinExchange &operator=(const BitcoinExchange &o);
    ~BitcoinExchange();

    void calculate(std::string input_fn);
};