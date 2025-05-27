#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(std::string db_filename) : db_(buildDb(db_filename)) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &o) : db_(o.db_) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &o) 
{
    if (this != &o)
        db_ = o.db_;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::map<std::string, float> BitcoinExchange::buildDb(std::string db_filename)
{
    // Open the db file
    std::ifstream file(db_filename);
    if (!file.is_open())
        throw std::runtime_error("failed to load the database.");

    // The result.
    std::map<std::string, float> db;

    // when there is an empty line, means eof.
    bool empty_line_started;

    // Read the db line by line
    std::string line;
    while (std::getline(file, line))
    {
        if (empty_line_started && !line.empty())
            throw std::runtime_error("failed to load the database, check the format.");

        if (line.empty())
        {
            empty_line_started = true;
            continue;
        }


    }


}

void BitcoinExchange::calculate(std::string input_fn) 
{

}