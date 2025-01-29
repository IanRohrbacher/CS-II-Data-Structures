#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"
int main() {
    std::cout << "Testing assign\n"; 

    {
        stack<int> one;
        one.push(1);
        
        stack<int> two;
        
        two = one;
        
        assert(one.empty() == false);
        assert(one.top() == 1);
        
        assert(two.empty() == false);
        assert(two.top() == 1);
    }

    {
        stack<int> one;
        one.push(1);
        one.push(2);
        
        stack<int> two;
        
        two = one;
        
        assert(one.empty() == false);
        assert(one.top() == 2);
        
        assert(two.empty() == false);
        assert(two.top() == 2);
    }
   
    {
        stack<char> one;
        one.push('a');
        
        stack<char> two;
        
        two = one;
        
        assert(one.empty() == false);
        assert(one.top() == 'a');
        
        assert(two.empty() == false);
        assert(two.top() == 'a');
    }

    {
        stack<String> one;
        one.push("abcd");
        
        stack<String> two;
        
        two = one;
        
        assert(one.empty() == false);
        assert(one.top() == "abcd");
        
        assert(two.empty() == false);
        assert(two.top() == "abcd");
        assert(two.top() == one.top());
    }

    {
        stack<String> one;
        one.push("12345");
        one.push("abcd");
        stack<String> two;
        
        two = one;
        
        assert(one.empty() == false);
        assert(one.top() == "abcd");
        
        assert(two.empty() == false);
        assert(two.top() == "abcd");
        assert(two.top() == one.top());
    }

    std::cout << "Done testing assign\n"; 
}