#include <iostream>
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- String() --------------------\n";

    String str;

    assert(str == "");
    std::cout << "String: |" << str << "|\n";
    
    std::cout << "Done testing Default Constructor String()." << "\n\n";

    return 0;
}
