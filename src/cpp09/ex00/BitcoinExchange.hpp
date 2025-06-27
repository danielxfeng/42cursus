#pragma once
#include <string>
#include <map>

typedef enum e_file_type
{
    DATA,
    INPUT
} t_file_type;

std::string getFilename(const t_file_type file_type);
void trimStr(std::string &str);
std::string parseDate(const std::string &str);
bool parseEntry(std::pair<std::string, float> &entry, const t_file_type file_type, const std::string &str);

class BitcoinExchange
{
private:
    std::map<std::string, float> db_; // The data
    std::map<std::string, float> buildDb(std::string &db_fn); // The function to parse and build the db.

public:
    BitcoinExchange() = delete;
    BitcoinExchange(std::string db_filename);
    BitcoinExchange(const BitcoinExchange &o);
    BitcoinExchange &operator=(const BitcoinExchange &o);
    ~BitcoinExchange();

    void calculate(std::string input_fn);
};