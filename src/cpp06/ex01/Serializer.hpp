#pragma once
#include "Data.hpp"
#include <cstdint>

class Serializer
{
public:
    Serializer() = delete;
    Serializer(const Serializer &o) = delete;
    Serializer &operator=(const Serializer &o) = delete;

    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};