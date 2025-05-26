#pragma once
#include <deque>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    class iterator
    {
    private:
        typename std::deque<T>::reverse_iterator it_;

    public:
        iterator(typename std::deque<T>::reverse_iterator it) : it_(it) {}

        T &operator*() const { return *it_; }
        T *operator->() const { return &(*it_); }
        iterator &operator++()
        {
            ++it_;
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++it_;
            return tmp;
        }
        iterator &operator--()
        {
            --it_;
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            --it_;
            return tmp;
        }

        bool operator==(const iterator &other) const { return it_ == other.it_; }
        bool operator!=(const iterator &other) const { return it_ != other.it_; }
    };

    iterator begin() { return iterator(this->c.rbegin()); }
    iterator end() { return iterator(this->c.rend()); }
};