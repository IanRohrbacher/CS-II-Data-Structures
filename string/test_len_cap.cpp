#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- length() --------------------\n";

    {
        String str("Letters");

        assert(str.length() == 7);
        std::cout << "str.length() == 7: " << (str.length() == 7 ? "True" : "False") << "=True\n";

    }

    {
        String str("L");

        assert(str.length() == 1);
        std::cout << "str.length() == 1: " << (str.length() == 1 ? "True" : "False") << "=True\n";
    }

    {
        String str;

        assert(str.length() == 0);
        std::cout << "str.length() == 0: " << (str.length() == 0 ? "True" : "False") << "=True\n";
    }

    std::cout << "-------------------- capacity() --------------------\n";

    {
        String str("S2345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234E");

        assert(str.length() == str.capacity());
        std::cout << "str.length() == str.capacity(): " << (str.length() == str.capacity() ? "True" : "False") << "=True\n";
    }

    std::cout << "Done testing Length and Capacity\n\n";
    return 0;
}
