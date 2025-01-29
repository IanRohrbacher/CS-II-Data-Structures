#include "string.hpp"
#include <cassert>

// constructors
String::String() {
    for(int i = 0; i <= capacity(); i++) {
        str[i] = 0;
    }
}

String::String(char letter) : String() {

    str[0] = letter;
}

String::String(const char letters[]) : String() {
    int i = 0;
    while(letters[i] != 0 && i < capacity()) {
        str[i] = letters[i];
        i++;
    }
}



// functions
int String::capacity() const {
    return STRING_SIZE - 1;
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
            if((str[j] == word[j-i])) {
                count++;
            }
        }
        if(count == word.length()) {
            return i;
        }
    }
    return -1;
}



// overloaded functions
char& String::operator[](int num) {
    return str[num];
}

char String::operator[](int num) const {
    return str[num];
}

String& String::operator+=(const String& rhs) {
    int startLen = length();

    for(int i = 0; i < rhs.length(); i++) {
        if(i + startLen < capacity()) {
            str[i + startLen] = rhs[i];
        }
    }

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



// free functions
// TODO
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
    if(str.length() < 1) {
        return letter == str[0];
    }
    return false;
}

bool operator<(const char letters[], const String& str) {
    int i = 0;
    while(str[i] != 0 && letters[i] != 0 && str[i] == letters[i]) {
        i++;
    }
    return letters[i] < str[i];
}

bool operator<(char letter, const String& str) {
    return letter < str[0];
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
