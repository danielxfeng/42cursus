#include <gtest/gtest.h>
#include "BitcoinExchange.hpp"

TEST(TrimString, Test) {
    std::string str1 = " aa bb cc  ddd  ";
    trimStr(str1);
    EXPECT_EQ(str1, "aa bb cc  ddd");
    std::string str2 = " aa bb cc  ddd";
    trimStr(str2);
    EXPECT_EQ(str2, "aa bb cc  ddd");
    std::string str3 = "aa bb cc  ddd    ";
    trimStr(str3);
    EXPECT_EQ(str3, "aa bb cc  ddd");
    std::string str4 = "aa bb cc  ddd";
    trimStr(str4);
    EXPECT_EQ(str4, "aa bb cc  ddd");
}

TEST(ParseDate, Test) {
    EXPECT_EQ(parseDate("2002-07-12"), "2002-07-12");
    EXPECT_EQ(parseDate("2020-02-29"), "2020-02-29");
    EXPECT_THROW(parseDate("2002-1-1"), std::invalid_argument);
    EXPECT_THROW(parseDate(""), std::invalid_argument);
    EXPECT_THROW(parseDate("2002-11"), std::invalid_argument);
    EXPECT_THROW(parseDate("20221101"), std::invalid_argument);
    EXPECT_THROW(parseDate("11-01"), std::invalid_argument);
    EXPECT_THROW(parseDate("2010-13-01"), std::invalid_argument);
    EXPECT_THROW(parseDate("2010-12-32"), std::invalid_argument);
}

TEST(ParseEntry, Test) {
    std::pair<std::string, float> entry;
    EXPECT_TRUE(parseEntry(entry, DATA, "2012-01-01, 100"));
    EXPECT_FLOAT_EQ(entry.second, 100.0);
    EXPECT_TRUE(parseEntry(entry, DATA, "2012-01-01, 100.0"));
    EXPECT_FLOAT_EQ(entry.second, 100.0);
    EXPECT_TRUE(parseEntry(entry, DATA, "2012-01-01, 100f"));
    EXPECT_FLOAT_EQ(entry.second, 100.0);
    EXPECT_TRUE(parseEntry(entry, DATA, "2012-01-01, 100.0f"));
    EXPECT_FLOAT_EQ(entry.second, 100.0);
    EXPECT_TRUE(parseEntry(entry, DATA, "  2012-01-01 , 100.0f  "));
    EXPECT_FLOAT_EQ(entry.second, 100.0);
    EXPECT_TRUE(parseEntry(entry, DATA, "2012-01-01,100.0f"));
    EXPECT_FLOAT_EQ(entry.second, 100.0);
    EXPECT_FALSE(parseEntry(entry, DATA, "2012-01-01, 1,000.00"));
    EXPECT_FALSE(parseEntry(entry, DATA, "2012-01-01, 1 00.0"));
    EXPECT_FALSE(parseEntry(entry, DATA, "2012-01-01, 9999999999999999999999999999999999999999.00"));
    EXPECT_FALSE(parseEntry(entry, INPUT, "2012-01-01, 1,001.00"));
}

