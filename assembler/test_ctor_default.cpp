#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"
int main() {
    std::cout << "Testing ctor_default\n"; 

    {
        stack<int> test;
        assert(test.empty() == true); 
    }   
   
    {
        stack<String> test;
        assert(test.empty() == true); 
    }      

    {
        stack<char> test;
        assert(test.empty() == true); 
    }  
    
    {
        stack<double> test;
        assert(test.empty() == true); 
    }   
   
    {
        stack<bool> test;
        assert(test.empty() == true); 
    }      

    std::cout << "Done testing ctor_default\n"; 
}