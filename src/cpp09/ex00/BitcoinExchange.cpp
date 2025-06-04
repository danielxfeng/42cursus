#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

std::string getFilename(const t_file_type file_type)
{
    return file_type == DATA ? "data" : "input";
}

void trimStr(std::string &str)
{
    str.erase(0, str.find_first_not_of(" \t"));
    str.erase(str.find_last_not_of(" \t") + 1);
}

std::string parseDate(const std::string &str)
{
    if (str.length() != 10) // Only "2022-01-02" is supported
        throw std::invalid_argument("bad date format");
    tm tm{};
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail())
        throw std::invalid_argument("bad date format");
    return str;
}

/**
 * @brief To parse the entry to a kv pair.
 * @details
 * It splits the entry by the file type.
 * Then trims two parts
 * Tries to parse the date, or float.
 *
 * @param entry [output] the parsed kv pair.
 * @param file_type either DATA or INPUT.
 * @param str the raw string of the entry.
 * @return true on successful, otherwise returns false.
 */
bool parseEntry(std::pair<std::string, float> &entry, const t_file_type file_type, const std::string &str)
{
    const auto delimiter = file_type == DATA ? "," : "|";
    size_t pos = str.find(delimiter);
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad " << getFilename(file_type) << " =>" << str << "." << std::endl;
        return false;
    }
    auto str_date = str.substr(0, pos);
    trimStr(str_date);

    try
    {
        entry.first = parseDate(str_date);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << "Error: bad " << getFilename(file_type) << " =>" << str << "." << std::endl;
        ;
        return false;
    }

    auto str_value = str.substr(pos + 1);
    trimStr(str_value);
    if (!str_value.empty() && str_value.back() == 'f')
        str_value.erase(str_value.length() - 1);

    size_t end_sign = 0;
    try
    {
        entry.second = std::stof(str_value, &end_sign);
        if (end_sign != str_value.length())
            throw std::invalid_argument("invalid format");
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << "Error: bad " << getFilename(file_type) << " =>" << str << "." << std::endl;
        return false;
    }
    catch (std::out_of_range &e)
    {
        std::cerr << "Error: bad " << getFilename(file_type) << " =>" << str << "." << std::endl;
        return false;
    }

    if (entry.second < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (file_type == INPUT && entry.second > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

BitcoinExchange::BitcoinExchange(std::string db_filename) : db_(buildDb(db_filename)) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &o) : db_(o.db_) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &o)
{
    if (this != &o)
        db_ = o.db_;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/**
 * @details
 * 1 Check the file existance
 * 2 Skip the first line(header)
 * 3 Iterate the lines:
 *   3.1 Check empty line.
 *   3.2 Parse the line.
 *   3.3 For parsing error, terminate the app.
 *   3.4 Push to map, for duplicated key, terminate the app.
 */
std::map<std::string, float> BitcoinExchange::buildDb(std::string &db_filename)
{
    // Open the db file
    std::ifstream file(db_filename);
    if (!file.is_open())
        throw std::invalid_argument("Error: Could not open data file, the program is terminated.");

    // The result.
    std::map<std::string, float> db;

    // when there is an empty line, means eof.
    bool empty_line_started = false;

    // Read the db line by line
    std::string line;
    bool is_head = true;
    while (std::getline(file, line))
    {
        // Empty lines are allowed only in the end of a file.
        if (empty_line_started && !line.empty())
            throw std::runtime_error("Error: Incorrect empty line(s) found. Format of the data file is incorrect, the program is terminated.");

        // Set the flag, which means we are waiting for the EOF.
        if (line.empty())
        {
            empty_line_started = true;
            continue;
        }

        // Skip the first line, which means the title.
        if (is_head)
        {
            is_head = false;
            continue;
        }

        // Try to parse the entry.
        std::pair<std::string, float> entry;

        // For data, parsing error causes a fatal error.
        if (!parseEntry(entry, DATA, line))
            throw std::invalid_argument("Error: Entry in the data file is incorrect, the program is terminated.");

        // For data, dulicated key is also not allowed.
        auto res = db.insert(entry);
        if (!res.second)
            throw std::invalid_argument("Error: Duplicated key in the data file is incorrect, the program is terminated.");
    };

    return db;
}

/**
 * @details
 * 1 Check the file existance
 * 2 Skip the first line(header)
 * 3 Iterate the lines:
 *   3.1 Skip on parsing error.
 *   3.2 Calculate and print out.
 */
void BitcoinExchange::calculate(std::string input_fn)
{
    // Open the db file
    std::ifstream file(input_fn);
    if (!file.is_open())
        throw std::invalid_argument("Error: could not open file.");

    // Read the db line by line
    std::string line;
    bool is_head = true;
    while (std::getline(file, line))
    {

        // Set the flag, which means we are waiting for the EOF.
        if (line.empty())
        {
            std::cerr << "Error: bad input => " << line << "." << std::endl;
            continue;
        }

        // Skip the first line, which means the title.
        if (is_head)
        {
            is_head = false;
            continue;
        }

        // Try to parse the entry.
        std::pair<std::string, float> entry;

        // We skip the calculation on error.
        if (!parseEntry(entry, INPUT, line))
            continue;

        // We try to find the upperbound one.
        auto it = db_.upper_bound(entry.first);
        // Shift back.
        if (it == db_.end() || --it == db_.end())
        {
            std::cerr << "Error: data not found => " << line << "." << std::endl;
            continue;
        }

        // Calculate and print
        std::cout << entry.first << " => " << entry.second << " = " << entry.second * it->second << std::endl;
    };
}