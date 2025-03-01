#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- ==(String, String) --------------------\n";

    {
        String str1("Letters");
        String str2("Letters");

        assert(str1 == str2);
        std::cout << "str1 == str2: " << (str1 == str2 ? "True" : "False") << "=True\n";
    }

    {
        String str1("L");
        String str2('L');

        assert(str1 == str2);
        std::cout << "str1 == str2: " << (str1 == str2 ? "True" : "False") << "=True\n";
    }

    {
        String str1("S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E");
        String str2("S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E");

        assert(str1 == str2);
        std::cout << "str1 == str2: " << (str1 == str2 ? "True" : "False") << "=True\n";
    }

    std::cout << "-------------------- ==(char, String) --------------------\n";

    {
        String str("L");
        char letter = 'L';

        assert(str == letter);
        std::cout << "str1 == str2: " << (str == letter ? "True" : "False") << "=True\n";
    }

    std::cout << "-------------------- ==(char[], String) --------------------\n";

    {
        String str("Letters");
        char letters[] = "Letters";

        assert(str == letters);
        std::cout << "str1 == str2: " << (str == letters ? "True" : "False") << "=True\n";
    }

    {
        String str("Letters");
        char letters[] = "Letters";

        assert(letters == str);
        std::cout << "str1 == str2: " << (letters == str ? "True" : "False") << "=True\n";
    }

    {
        String str1("letters");
        String str2("Letters");

        assert(!(str1 == str2));
        std::cout << "str1 == str2: " << (str1 == str2 ? "True" : "False") << "=False\n";
    }

    std::cout << "Done testing Equals\n\n";
    return 0;
}
