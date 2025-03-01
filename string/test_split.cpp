#include <iostream> 
#include <cassert>
#include <vector>
#include "string.hpp"

int main () {
    std::cout << "-------------------- split(char) --------------------\n";

    {
        String str("Hello World!");
        std::vector<String> vector;

        vector = str.split(' ');

        std::cout << "|" << vector[0] << "|" << vector[1] << "|\n"; 

        assert(vector[0] == "Hello");
        std::cout << "vector[0] == \"Hello\": " << (vector[0] == "Hello" ? "True" : "False") << "=True\n";

        assert(vector[1] == "World!");
        std::cout << "vector[1] == \"World!\": " << (vector[1] == "World!" ? "True" : "False") << "=True\n";
    }

    std::cout << '\n';

    {
        String str("abc ef gh");
        std::vector<String> vector;

        vector = str.split(' ');

        assert(vector[0] == "abc");
        std::cout << "vector[0] == \"abc\": " << (vector[0] == "abc" ? "True" : "False") << "=True\n";

        assert(vector[1] == "ef");
        std::cout << "vector[1] == \"ef\": " << (vector[1] == "ef" ? "True" : "False") << "=True\n";

        assert(vector[2] == "gh");
        std::cout << "vector[2] == \"gh\": " << (vector[2] == "gh" ? "True" : "False") << "=True\n";
    }

    std::cout << '\n';

    {
        String str("-a--b-");
        std::vector<String> vector;

        vector = str.split('-');

        assert(vector[0] == "");
        std::cout << "vector[0] == \"\": " << (vector[0] == "" ? "True" : "False") << "=True\n";

        assert(vector[1] == "a");
        std::cout << "vector[1] == \"a\": " << (vector[1] == "a" ? "True" : "False") << "=True\n";

        assert(vector[2] == "");
        std::cout << "vector[2] == \"\": " << (vector[2] == "" ? "True" : "False") << "=True\n";

        assert(vector[3] == "b");
        std::cout << "vector[3] == \"b\": " << (vector[3] == "b" ? "True" : "False") << "=True\n";

        assert(vector[4] == "");
        std::cout << "vector[4] == \"\": " << (vector[4] == "" ? "True" : "False") << "=True\n";        
    }

    std::cout << "Done testing Split\n\n";
    return 0;
}
