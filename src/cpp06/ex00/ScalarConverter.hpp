#pragma once
#include <string>

typedef enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN,
} t_type;

class ScalarConverter {
    public:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter &o) = delete;
        ScalarConverter &operator=(const ScalarConverter &o) = delete;

        static void convert(const std::string &str);
};