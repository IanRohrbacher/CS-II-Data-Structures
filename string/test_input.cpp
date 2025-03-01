#include <iostream> 
#include <fstream>
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- >> --------------------\n";

    std::ifstream file1("log_1_tiny.txt");
    std::ifstream file2("log_2_small.txt");
    std::ifstream file3("log_3_medium.txt");

    if(file1.is_open() && file2.is_open() && file3.is_open()) {
        {
            String str;

            file1 >> str;

            assert(str == "131.123.47.176");
            std::cout << "file1 >> str : " << (str == "131.123.47.176" ? "True" : "False") << "=True\n";

        }

        {
            String str;

            file2 >> str;

            assert(str == "131.123.47.176");
            std::cout << "file1 >> str : " << (str == "131.123.47.176" ? "True" : "False") << "=True\n";

        }

        {
            String str;

            file2 >> str;

            assert(str == "-");
            std::cout << "file1 >> str : " << (str == "-" ? "True" : "False") << "=True\n";

        }
    } else {
        std::cout << "Unable To Open File\n";
    }

    file1.close();
    file2.close();
    file3.close();

    std::cout << "Done testing Input\n\n";
    return 0;
}
