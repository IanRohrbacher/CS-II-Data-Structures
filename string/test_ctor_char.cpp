#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- String(char) --------------------\n";

    {
        String str(' ');

        assert(str == ' ');
        std::cout << "char[] String: |" << str << "|\n";

    }

    {
        String str('1');

        assert(str == '1');
        std::cout << "char[] String: |" << str << "|\n";
    }

    {
        String str('\0');

        assert(str == "");
        std::cout << "char[] String: |" << str << "| " << "len = " << str.length() << '\n';
    }

    std::cout << "Done testing Constructor String(char)\n\n";
    return 0;
}
