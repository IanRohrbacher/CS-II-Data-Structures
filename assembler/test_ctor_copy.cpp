#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"
int main() {
    std::cout << "Testing assign\n"; 
    
    {
        stack<int> test;
        test.push(1);
        stack<int> copyTest(test);
        
        assert(test.top() == copyTest.top()); 
    }

    {
        stack<char> test;
        test.push('a');
        stack<char> copyTest(test);
        
        assert(test.top() == copyTest.top()); 
    }

    {
        stack<char> test;
        test.push('a');
        test.push('b');
        stack<char> copyTest(test);
        
        assert(test.top() == copyTest.top()); 
    }

    {
        stack<int> test;
        test.push(1);
        test.push(2);
        stack<int> copyTest(test);
        
        assert(test.top() == copyTest.top()); 
    }

    {
        stack<String> test;
        test.push("Abc");
        test.push("def");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top()); 
    }

    {
        stack<String> test;
        test.push("Abc");
        test.push("def");
        test.push("1234224");
        stack<String> copyTest(test);
        
        assert(test.top() == copyTest.top()); 
    }

    std::cout << "Done testing assign\n"; 
}