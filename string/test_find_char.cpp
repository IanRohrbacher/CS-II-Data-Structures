#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- findch() --------------------\n";

    {
        String str("Hello World!");

        assert(str.findch(0, 'e') == 1);
        std::cout << "str.findch(0, 'e') == 1: " << (str.findch(0, 'e') == 1 ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.findch(0, 'l') == 2);
        std::cout << "str.findch(0, 'l') == 2: " << (str.findch(0, 'l') == 2 ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.findch(3, 'l') == 3);
        std::cout << "str.findch(0, 'l') == 3: " << (str.findch(0, 'l') == 3 ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.findch(4, 'l') == 9);
        std::cout << "str.findch(0, 'l') == 9: " << (str.findch(0, 'l') == 9 ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.findch(0, 'H') == 0);
        std::cout << "str.findch(0, 'H') == 0: " << (str.findch(0, 'H') == 0 ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello horld!");

        assert(str.findch(0, 'h') == 6);
        std::cout << "str.findch(0, 'h') == 6: " << (str.findch(0, 'h') == 6 ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello horld!");

        assert(str.findch(0, '!') == 11);
        std::cout << "str.findch(0, '!') == 11: " << (str.findch(0, '!') == 11 ? "True" : "False") << "=True\n";

    }

    std::cout << "Done testing Find Char\n\n";
    return 0;
}
