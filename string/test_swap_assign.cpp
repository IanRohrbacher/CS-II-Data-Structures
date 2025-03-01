#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- swap() --------------------\n";

    {
        String str1("Hello World!");
        String str2;

        str2.swap(str1);

        assert(str2 == "Hello World!");
        std::cout << "str2 == \"Hello World!\": " << (str2 == "Hello World!" ? "True" : "False") << "=True\n";

    }

    {
        String str1("Hello World!");

        str1.swap(str1);

        assert(str1 == "Hello World!");
        std::cout << "str1 == \"Hello World!\": " << (str1 == "Hello World!" ? "True" : "False") << "=True\n";

    }

    std::cout << "Done testing Swap\n\n";
    return 0;
}
