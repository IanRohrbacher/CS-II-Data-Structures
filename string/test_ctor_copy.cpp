#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- String(const String&) --------------------\n";


    String str1("Hello World!");
    String str2;

    str2 = str1;

    assert(str1 == str2);
    std::cout << "str1 == str2: " << (str1 == str2 ? "True" : "False") << "=True\n";


    std::cout << "Done testing Copy Constructor String(const String&)\n\n";
    return 0;
}
