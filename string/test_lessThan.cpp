#include <iostream> 
#include <cassert>
#include "string.hpp"

int main () {
    std::cout << "-------------------- < --------------------\n";

    {
        String str1("Letters");
        String str2("Letter");

        assert(!(str1 < str2));
        std::cout << "str1 == str2: " << (str1 < str2 ? "True" : "False") << "=False\n";

    }

    {
        String str1("Letter");
        String str2("Letters");

        assert(str1 < str2);
        std::cout << "str1 == str2: " << (str1 < str2 ? "True" : "False") << "=True\n";

    }

    {
        String str1("Letters");
        String str2("Letters");

        assert(!(str1 < str2));
        std::cout << "str1 == str2: " << (str1 < str2 ? "True" : "False") << "=False\n";

    }

    {
        String str1("letters");
        String str2("Letters");

        assert(!(str1 < str2));
        std::cout << "str1 == str2: " << (str1 < str2 ? "True" : "False") << "=False\n";

    }

    {
        String str1("Letters");
        String str2("letters");

        assert(str1 < str2);
        std::cout << "str1 == str2: " << (str1 < str2 ? "True" : "False") << "=True\n";

    }

    {
        String str1("letters");
        String str2("letters");

        assert(!(str1 < str2));
        std::cout << "str1 == str2: " << (str1 < str2 ? "True" : "False") << "=False\n";

    }

    std::cout << "-------------------- < --------------------\n";

    {
        String str("Letters");

        assert(str < 'P');
        std::cout << "str < \'P\': " << (str < 'P' ? "True" : "False") << "=True\n";

    }

    {
        String str("Letters");

        assert(!(str < 'A'));
        std::cout << "str < \'A\': " << (str < 'A' ? "True" : "False") << "=False\n";

    }

    std::cout << "Done testing Less Then\n\n";
    return 0;
}
