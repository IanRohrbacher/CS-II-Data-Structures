#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- [] --------------------\n";

    {
        String str("Letters");

        assert(str[0] == 'L');
        std::cout << "str[0]: " << (str[0] == 'L' ? "True" : "False") << "=True\n";
    }

    {
        String str("letters");

        str[0] = 'L';

        assert(str[0] == 'L');
        std::cout << "str[0] = \'L\': " << (str[0] == 'L' ? "True" : "False") << "=True\n";
    }

    {
        String str1("letters");
        String str2("sretteL");

        str1[0] = str2[6];

        assert(str1[0] == 'L');
        assert(str2 == "sretteL");
        std::cout << "str1[0] = 'L': " << (str1[0] == 'L' ? "True" : "False") << "=True && " << "str2 = \"sretteL\": " << (str2 == "sretteL" ? "True" : "False") << "=True\n";
    }

    {
        String str("sretteL");
        char letter = str[0];

        assert(str == "sretteL");
        assert(letter == 's');
        std::cout << "str == \"sretteL\": " << (str == "sretteL" ? "True" : "False") << "=True && " << "letter == \'s\': " << (letter == 's' ? "True" : "False") << "=True\n";
    }

    {
        String str("Letters");

        assert(!(str[0] == 'l'));
        std::cout << "str[0]: " << (str[0] == 'l' ? "True" : "False") << "=False\n";
    }

    {
        String str("S2345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234E");

        assert((str[str.capacity()-1] == 'E'));
        std::cout << "str[str.capacity()-1]: " << (str[str.capacity()-1] == 'E' ? "True" : "False") << "=True\n";
    }

    {
        String str("S2345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234E");

        assert((str[str.capacity()] == 0));
        std::cout << "str[str.capacity()]: " << (str[str.capacity()] == 0 ? "True" : "False") << "=True\n";
    }


    std::cout << "Done testing Subscript\n\n";
    return 0;
}
