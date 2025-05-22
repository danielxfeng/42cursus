#pragma once

class Data
{
private:
    const int value_;

public:
    Data();
    Data(int value);
    Data(const Data &o);
    Data &operator=(const Data &o) = delete;
    ~Data();
    int getValue();
};