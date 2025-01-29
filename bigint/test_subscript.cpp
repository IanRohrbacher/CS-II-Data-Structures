// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    
    //Add test cases!!

{
        // Setup
        bigint bi("19725609");

        // Test 
        int digit = bi[3];

        // Verify
        assert(bi    == 19725609);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 5);
    }

    {
        // Setup
        bigint bi(1234567890);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == "1234567890");  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 0);
    }

    {
        // Setup
        bigint bi(130630230);

        // Test 
        int digit = bi[8];

        // Verify
        assert(bi    == "130630230");  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 1);
    }


    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

