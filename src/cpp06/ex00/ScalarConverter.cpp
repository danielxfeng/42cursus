#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>

bool isChar(const std::string &str)
{
    if (str.length() != 3 || str[0] != '\'' || str[2] != '\'')
        return false;
    return true;
}

bool isInt(const std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (i == 0 && (str[i] == '+' || str[i] == '-'))
            continue;
        if (isdigit(str[i]))
            continue;
        return false;
    }
    return true;
}

bool isFloat(const std::string &str)
{
    bool has_dot = false;
    bool has_digit = false;
    if (str.back() != 'f')
        return false;
    const size_t end = str.length() - 1;
    for (size_t i = 0; i < end; ++i)
    {
        // The first +-;
        if (i == 0 && (str[i] == '+' || str[i] == '-'))
            continue;
        // check dot: only one
        if (str[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
            continue;
        }
        // check digit, at least a digit is needed.
        if (isdigit(str[i]))
        {
            has_digit = true;
            continue;
        }
        return false;
    }
    if (!has_digit)
        return false;
    return true;
}

bool isDouble(const std::string &str)
{
    bool has_dot = false;
    bool has_digit = false;
    const size_t end = str.length();
    for (size_t i = 0; i < end; ++i)
    {
        // The first +-;
        if (i == 0 && (str[i] == '+' || str[i] == '-'))
            continue;
        // check dot: only one
        if (str[i] == '.')
        {
            if (has_dot)
                return false;
            has_dot = true;
            continue;
        }
        // check digit, at least a digit is needed.
        if (isdigit(str[i]))
        {
            has_digit = true;
            continue;
        }
        return false;
    }
    if (!has_digit || !has_dot)
        return false;
    return true;
}

void printCharType (const char c)
{
    if (isprint(c)) 
    {
        std::cout << "char: '" << c << "'" << std::endl;
        const int n = static_cast<int>(c);
        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << n << ".0f" << std::endl;
        std::cout << "double: " << n << ".0" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void printChar(const double n)
{
    if (isprint(n))
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

bool isIntOutflow(const double n)
{
    if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
        return true;
    return false;
}

void printInt(const double n)
{
    if (isIntOutflow(n))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(n) << std::endl;
}

void printFloat(const double n)
{
    if (n > std::numeric_limits<float>::max() || n < std::numeric_limits<float>::min())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
}

double convertToDouble(const std::string str)
{
    double value = 0;
    try
    {
        value = std::stod(str);
        return value;
    }
    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return std::numeric_limits<double>::max();
    }
}

void ScalarConverter::convert(const std::string &str)
{
    if (str.empty())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // pseudo-literal
    if (str == "nan" || str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        const std::string sign = str[0] == '-' ? "-" : "+";
        std::cout << "float: " << sign << "inff" << std::endl;
        std::cout << "double: " << sign << "inf" << std::endl;
        return;
    }

    // determine the type
    t_type type = UNKNOWN;
    if (isChar(str))
        type = CHAR;
    else if (isInt(str))
        type = INT;
    else if (isFloat(str))
        type = FLOAT;
    else if (isDouble(str))
        type = DOUBLE;

    // print
    switch (type)
    {
    case CHAR:
    {
        printCharType(str[1]);
        return;
    }
    // will fall through to `double`
    case INT:
    case FLOAT:
    case DOUBLE:
    {
        double value = convertToDouble(str);
        if (value == std::numeric_limits<double>::max())
            return;
        printChar(value);
        printInt(value);
        printFloat(value);
        std::cout << "double: " << value << std::endl;
        return;
    }
    default:
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    }
}