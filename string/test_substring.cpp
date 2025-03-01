#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- substr() --------------------\n";

    {
        String str("Hello World!");

        assert(str.substr(0, str.length()) == "Hello World!");
        std::cout << "str.substr(0, str.length()) == \"Hello World!\": " << (str.substr(0,str.length()) == "Hello World!" ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.substr(0, 4) == "Hello");
        std::cout << "str.substr(0, 5) == \"Hello\": " << (str.substr(0, 5) == "Hello" ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.substr(6, str.length()) == "World!");
        std::cout << "str.substr(6, str.length()) == \"World!\": " << (str.substr(6,str.length()) == "World!" ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.substr(0, 0) == "H");
        std::cout << "str.substr(0, 0) == \"\": " << (str.substr(0, 0) == "" ? "True" : "False") << "=True\n";

    }

    {
        String str("Hello World!");

        assert(str.substr(1, 1) == "e");
        std::cout << "str.substr(1, 1) == \"\": " << (str.substr(1, 1) == "" ? "True" : "False") << "=True\n";

    }

    std::cout << "Done testing Substring\n\n";
    return 0;
}
