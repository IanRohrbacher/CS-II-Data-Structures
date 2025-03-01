#include "string.hpp"
#include <cassert>

// constructors
String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[capacity()] = 0;
}

String::String(char letter) {
    stringSize = ((letter == '\0') ? 1 : 2);
    str = new char[stringSize];
    str[0] = letter;
    str[capacity()] = 0;
}

String::String(const char letters[]) {
    int j = 0;
    while(letters[j] != 0) {
        j++;
    }

    stringSize = j+1;
    str = new char[stringSize];

    for(int i = 0; ((i < j) && (i < capacity())); i++) {
        str[i] = letters[i];
    }

    str[capacity()] = 0;
}

String::String(const String& copy) {
    stringSize = copy.stringSize;
    str = new char[stringSize];

    for(int i = 0; i < stringSize; i++) {
        str[i] = copy[i];
    }

    str[capacity()] = 0;
}

String::~String() {
    stringSize = 0;
    delete[] str;
    str = nullptr;
}



// functions
int String::capacity() const {
    return stringSize - 1;
}

int String::length() const {
    int i = 0;
    while(str[i] != 0) {
        i++;
    }
    return i;
}

String String::substr(int in, int ex) const {
    String result;
    for(int i = in; i <= ex; i++) {
        result += str[i];
    }
    return result;
}

int String::findch(int start, char letter) const {
    for(int i = start; i < length(); i++) {
        if(str[i] == letter) {
            return i;
        }
    }
    return -1;
}

int String::findstr(int start, const String& word) const {
    for(int i = start; i < length() - word.length() + 1; i++) {
        int count = 0;
        for(int j = i ; j < word.length() + i; j++) {
            if(str[j] == word[j-i]) {
                count++;
            }
        }
        if(count == word.length()) {
            return i;
        }
    }
    return -1;
}

void String::swap(String& s) {
    char* tempChar = str;
    int tempInt = stringSize;

    str = s.str;
    stringSize = s.stringSize;

    s.str = tempChar;
    s.stringSize = tempInt;
}

std::vector<String> String::split(char letter) const {
    std::vector<String> result;
    String temp;
    int i = 0;
    while(i <= length()) {
        temp = String(substr(i, findch(i, letter) == -1 ? length() : findch(i, letter)-1));
        result.push_back(temp);
        i = (findch(i, letter) == -1 ? length() : findch(i, letter)) + 1;
    }
    return result;
}



// overloaded functions
char& String::operator[](int num) {
    return str[num];
}

char String::operator[](int num) const {
    return str[num];
}

String& String::operator+=(const String& rhs) {
    int newCap = length()+rhs.length();
    char *tempChar = new char[newCap+1];

    for(int i = 0; i < length(); i++) {
        tempChar[i] = str[i];
    }

    for(int i = length(); i < length() + rhs.length(); i++) {
        tempChar[i] = rhs[i - length()];
    }

    stringSize = newCap + 1;
    tempChar[capacity()] = 0;

    delete[] str;

    str = tempChar;
    tempChar = nullptr;

    return *(this);
}

bool String::operator==(const String& rhs) const {
    if(length() == rhs.length()) {
        for(int i = 0; i < length(); i++) {
            if(str[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool String::operator<(const String& rhs) const {
    int i = 0;
    while(str[i] != 0 && rhs[i] != 0 && str[i] == rhs[i]) {
        i++;
    }
    return str[i] < rhs[i];
}

String& String::operator=(String rhs) {
    swap(rhs);
    return *this;
}



// free functions
String operator+(String lhs, const String& rhs) {
    return lhs += rhs;
}

bool operator==(const char letters[],  const String& str) {
    int charLen = 0;
    while(letters[charLen] != 0) {
        charLen++;
    }
    if(charLen == str.length()) {
        for(int i = 0; i < charLen; i++) {
            if(letters[i] != str[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator==(char letter, const String& str) {
    if(str.length() == 1) {
        return letter == str[0];
    }
    return false;
}

bool operator<(const char letters[], const String& str) {
    return String(letters) < str;
}

bool operator<(char letter, const String& str) {
    return String(letter) < str;
}

bool operator<=(const String& lhs, const String& rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator>=(const String& lhs, const String& rhs) {
    return (rhs < lhs || lhs == rhs);
}

bool operator>(const String& lhs, const String& rhs) {
    return rhs < lhs;
}



// IO functions
std::istream& operator>>(std::istream& in, String& rhs) {
    char buff[255];

    in >> buff;

    if(!in.eof()) {
        rhs = String(buff);
    } else {
        rhs = String();
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    for(int i = 0; i < rhs.length(); i++) {
        out << rhs[i];
    }
    return out;
}
