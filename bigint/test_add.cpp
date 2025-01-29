// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    //Add test cases as needed.

    // 6-8 test cases
    /*
    assert(1 == 2); //WRONG. This will fail, of course.
                    //You need to add more test cases here. Remove this assert.
    */
    {
      bigint left(2147483647);
      bigint right(2147483647);
      bigint result;

      result = left + right;
      
      assert(left   == 2147483647);
      assert(right  == 2147483647);
      assert(result == "4294967294");

      std::cout << result << "=" << left << "+" << right << " | " << (result == "4294967294" ? "True" : "Fase") << "\n";
    }

    {
      bigint left("2147483647");
      bigint right(2147483647);
      bigint result;

      result = left + right;
      
      assert(left   == 2147483647);
      assert(right  == 2147483647);
      assert(result == "4294967294");
      std::cout << result << "=" << left << "+" << right << " | " << (result == "4294967294" ? "True" : "Fase") << "\n";
    }

    {
      bigint left(999999);
      bigint right(1);
      bigint result;

      result = left + right;
      
      assert(left   == 999999);
      assert(right  == 1);
      assert(result == 1000000);
      std::cout << result << "=" << left << "+" << right << " | " << (result == 1000000 ? "True" : "Fase") << "\n";
    }

    {
      bigint left("13579");
      bigint right("24680");
      bigint result;

      result = left + right;
      
      assert(left   == 13579);
      assert(right  == 24680);
      assert(result == 38259);
      std::cout << result << "=" << left << "+" << right << " | " << (result == 38259 ? "True" : "Fase") << "\n";
    }

    {
      bigint left("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      bigint right(1);
      bigint result;

      result = left + right;
      
      assert(left   == "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      assert(right  == 1);
      assert(result == 0);
      std::cout << result << "=" << left << "+" << right << " | " << (result == 0 ? "True" : "Fase") << "\n";
    }

    {
      bigint left("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      bigint right(2);
      bigint result;

      result = left + right;
      
      assert(left   == "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      assert(right  == 2);
      assert(result == 1);
      std::cout << result << "=" << left << "+" << right << " | " << (result == 1 ? "True" : "Fase") << "\n";
    }

    {
      bigint left(2);
      bigint right("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      bigint result;

      result = left + right;
      
      assert(left  == 2);
      assert(right   == "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
      assert(result == 1);
      std::cout << result << "=" << left << "+" << right << " | " << (result == 1 ? "True" : "Fase") << "\n";
    }

    
    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

