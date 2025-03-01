#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- findstr() --------------------\n";

    {
        String str1("Hello World!");
        String str2("Hello");

        assert(str1.findstr(0, str2) == 0);
        std::cout << "str1.findstr(0, str2) == 0: " << (str1.findstr(0, str2) == 0 ? "True" : "False") << "=True\n";
    }

    {
        String str1("Hello World!");
        String str2("ll");

        assert(str1.findstr(0, str2) == 2);
        std::cout << "str1.findstr(0, str2) == 2: " << (str1.findstr(0, str2) == 2 ? "True" : "False") << "=True\n";

    }

    {
        String str1("Hello World!");
        String str2("ll");

        assert(str1.findstr(3, str2) == -1);
        std::cout << "str1.findstr(3, str2) == -1: " << (str1.findstr(3, str2) == -1 ? "True" : "False") << "=True\n";

    }

    {
        String str1("Hello World!");
        String str2("World!");

        assert(str1.findstr(0, str2) == 6);
        std::cout << "str1.findstr(0, str2) == 6: " << (str1.findstr(0, str2) == 6 ? "True" : "False") << "=True\n";

    }

    {
        String str1("Hello World!");
        String str2("world!");

        assert(str1.findstr(0, str2) == -1);
        std::cout << "str1.findstr(0, str2) == -1: " << (str1.findstr(0, str2) == -1 ? "True" : "False") << "=True\n";

    }

    {
        String str1("Hello World!");
        String str2("World!");

        std::cerr << str1.findstr(6, str2) << '\n';

        assert(str1.findstr(6, str2) == 6);
        std::cout << "str1.findstr(6, str2) == 6: " << (str1.findstr(6, str2) == 6 ? "True" : "False") << "=True\n";

    }

    std::cout << "Done testing Find String\n\n";
    return 0;
}
