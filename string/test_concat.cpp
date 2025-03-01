#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- += --------------------\n";

    {
        String str1("Let");
        String str2("Ters");

        str1 += str2;

        assert(str1 == "LetTers");
        std::cout << "str1 = LetTers: " << (str1 == "LetTers" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Lett");
        String str2("ers");

        str1 += str2;

        assert(str1 == "Letters");
        std::cout << "str1 = Letters: " << (str1 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Let");
        String str2("ter");

        str1 += str2;

        assert(str1 == "Letter");
        std::cout << "str1 = Letter: " << (str1 == "Letter" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Letters");
        String str2;

        str1 += str2;
        
        assert(str1 == "Letters");
        std::cout << "str1 = Letters: " << (str1 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Letter");
        String str2('s');

        str1 += str2;
        
        assert(str1 == "Letters");
        std::cout << "str1 = Letters: " << (str1 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1;
        String str2("Letters");

        str1 += str2;

        assert(str1 == "Letters");
        std::cout << "str1 = Letters: " << (str1 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1("S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345");
        String str2("678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E");

        str1 += str2;

        assert(str1 == "S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E");
        std::cout << "str1 = S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E: " << (str1 == "S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E" ? "True" : "False") << "=True\n";
    }

    // {
    //     String str("Letters");

    //     str += str;

    //     std::cerr << "|" << str << "|\n";

    //     assert(str == "LettersLetters");
    //     std::cout << "str = LettersLetters: " << (str == "LettersLetters" ? "True" : "False") << "=True\n";
    // }

    std::cout << "-------------------- + --------------------\n";

    {
        String str1("Let");
        String str2("ters");
        String str3;

        str3 = str1 + str2;

        assert(str3 == "Letters");
        std::cout << "str3 = Letters: " << (str3 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Lett");
        String str2("ers");
        String str3;

        str3 = str1 + str2;

        assert(str3 == "Letters");
        std::cout << "str3 = Letters: " << (str3 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Let");
        String str2("ter");
        String str3;

        str3 = str1 + str2;

        assert(str3 == "Letter");
        std::cout << "str3 = Letter: " << (str3 == "Letter" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Letters");
        String str2;
        String str3;

        str3 = str1 + str2;
        
        assert(str3 == "Letters");
        std::cout << "str3 = Letters: " << (str3 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1;
        String str2("Letters");
        String str3;

        str3 = str1 + str2;

        assert(str3 == "Letters");
        std::cout << "str3 = Letters: " << (str3 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1("Letter");
        String str2('s');
        String str3;

        str3 = str1 + str2;
        
        assert(str3 == "Letters");
        std::cout << "str3 = Letters: " << (str3 == "Letters" ? "True" : "False") << "=True\n";
    }

    {
        String str1("S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345");
        String str2("678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E");
        String str3;

        str3 = str1 + str2;

        assert(str3 == "S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E");
        std::cout << "str3 = S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E: " << (str3 == "S23456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345E" ? "True" : "False") << "=True\n";
    }

    {
        String str("Letters");

        str = str + str;

        assert(str == "LettersLetters");
        std::cout << "str = LettersLetters: " << (str == "LettersLetters" ? "True" : "False") << "=True\n";
    }

    std::cout << "Done testing Concatenation\n\n";
    return 0;
}
