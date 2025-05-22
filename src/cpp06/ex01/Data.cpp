# include "Data.hpp"

Data::Data() : value_(0) {}
Data::Data(int value) : value_(value) {}
Data::Data(const Data &o) : value_(o.value_) {}
Data::~Data() {}
int Data::getValue() { return value_; }