#ifndef BIGINT_HPP_
#define BIGINT_HPP_

#include <iostream>

const int CAPACITY = 200;

class bigint {
public:
    bigint(); // Milestone 1
    bigint(int num); // Milestone 1
    bigint(const char num[]); // Milestone 1

    void debugPrint(std::ostream& out) const; // Milestone 1
    bigint timesDigit(int num) const; // Milestone 3
    bigint times10(int num) const; // Milestone 3
    bigint nfact() const; // extra credit
    int trailingZero() const; // extra credit
    
    bool operator==(const bigint& rhs) const; // Milestone 1
    bigint operator+ (const bigint& rhs) const; // Milestone 2
    int operator[] (int index) const; // Milestone 2
    bigint operator* (const bigint& rhs) const; // Milestone 3

    friend std::ostream& operator<< (std::ostream& out, const bigint& bi); // Milestone 1
    friend std::istream& operator>> (std::istream& in, bigint& bi); // Milestone 2

private:
    int numberList[CAPACITY];

    int leadingZero(const int* biList) const; // Milestone 1
};

#endif
