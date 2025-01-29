#include <iostream> 
#include "bigint.hpp"

// constructors
bigint::bigint() {
    for (int i = 0; i < CAPACITY; i++) {
        numberList[i] = 0;
    }
}

bigint::bigint(int num) : bigint(){
    for (int i = 0; i < CAPACITY; i++) {
        numberList[i] = num % 10;
        num = num / 10;
    }
}

bigint::bigint(const char num[]) : bigint() {
    int len = 0;
    for (int i=0; num[i]!=0; i++) {
        len++;
    }
    
    for (int i=0; i<len; i++) {
        numberList[i] = int(num[(len - 1) - i]-'0');
    }
}

// methods
void bigint::debugPrint(std::ostream& out) const {
    for (int i=(CAPACITY - 1); i>=0; i--) {
        out << numberList[i] <<  "|";
    }
    out << std::endl;
}

// gets the ith index where the number starts
int bigint::leadingZero(const int* biList) const {
    for (int i = (CAPACITY - 1); i >= 0; i--) {
        if (biList[i] != 0) {
            return i;
        }
    }
    return -1;
}

// multiples a bigint by one digit 0-9
bigint bigint::timesDigit(int num) const {
    bigint temp;
    int thisStart = leadingZero(numberList);
    int thisTempNum = 0;

    for (int i = 0; i <= thisStart; i++) {
        thisTempNum = numberList[i];
        bigint tempBigint((thisTempNum * num));
        temp = temp + tempBigint.times10(i);
    }
    return temp;
}

// takes a number and multiples it 10^(num)
bigint bigint::times10(int num) const {
    bigint temp;
    for (int j = 0; j <= leadingZero(numberList); j++) {
        for (int i = num; i >= 0; i--) {
            temp.numberList[j+i+num] = numberList[j+i];
        }
        // fills in [0,j) with 0
        for (int i = 0; i < num; i++) {
            temp.numberList[i] = 0;
        }
    }
    return temp;
}

// starts at 1 and goes up to current bigint
bigint bigint::nfact() const {
    bigint count(1);
    bigint result(1);
    bigint one(1);
    if(*this == 0) {
        return one;
    }

    while(!(*this == count)) {
        result = result * count;
        count = count + one;
    }

    return result*count;
}

// gets the amout of zeros on the right
int bigint::trailingZero() const {
    for (int i = 0; i < CAPACITY; i++) {
        if (nfact().numberList[i] != 0) {
            return i;
        }
    }
    return -1;
}

// overload operators
bool bigint::operator==(const bigint& rhs) const {
    for (int i = 0; i < CAPACITY; i++) {
        if (numberList[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

// pulls the ith index, adds them, if > 10 carrys = true, then on the next loop +1 if carry is true
bigint bigint::operator+ (const bigint& rhs) const {
    bigint tempBigint(0);
    int tempNum = 0;
    bool carry = false;
    for (int i = 0; i < CAPACITY; i++) {
        tempNum = carry ? numberList[i] + rhs[i] + 1 : numberList[i] + rhs[i];
        if (tempNum >= 10) {
            carry = true;
            tempNum = tempNum % 10;
        }
        else {
            carry = false;
        }
        tempBigint.numberList[i] = tempNum;
    }
    return tempBigint;
}


// returns index of numberList
int bigint::operator[] (int index) const {
    return numberList[index];
}

// TODO something not working
bigint bigint::operator* (const bigint& rhs) const {
    bigint temp, finalTemp;
    int rhsStart = leadingZero(rhs.numberList);

    if (!(leadingZero(numberList) == -1 || rhsStart == -1)) {
        for (int i = 0; i <= rhsStart; i++) {
            temp = timesDigit(rhs.numberList[i]);
            finalTemp = finalTemp + temp.times10(i);
        }
    }
    return finalTemp;
}

// IO 
// starts from the highest index thats not zero and prints from there backwards
std::ostream& operator<<(std::ostream& out, const bigint& bi) {
    int start = bi.leadingZero(bi.numberList);
    if (start != -1) {
        for (int i = start; i >= 0; i--) {
            out << bi[i];
        }
    } else {
        out << 0;
    }
    return out;
}

std::istream& operator>> (std::istream& in, bigint& bi) {
    char tempCharList[CAPACITY]{};
    char tempCharIn;
    int index = 0;

    in >> tempCharIn;

	while (tempCharIn != ';' && !in.eof()) {
		tempCharList[index] = tempCharIn;
		in >> tempCharIn;
		index++;
	}

	tempCharList[index] = 0;
	bi = bigint(tempCharList);

	return in;
}
