#include <iostream>

class Test {
    public:
        Test();
        ~Test();
        Test(const Test&);

        Test operator=(const Test&);
    private:
};

Test::Test(){
    std::cout << "Default Constructor called\n";
}

Test::~Test(){
    std::cout << "Destructor called\n";
}

Test::Test(const Test& copy){
    std::cout << "Copy Constructor called\n";
}

Test Test::operator=(const Test& rhs){
    Test temp;
    std::cout << "Assignment called\n";
    return temp;
}

void testCopyCtor(Test test){
    std::cout << "Function called\n";
    // dtor is called
}

int main() {
    //Tests Default ctor
    Test one;
    Test two;

    //Tests Assignment
    one = two;
    two = one;

    //Tests copy ctor
    testCopyCtor(one);
    testCopyCtor(one);
    
    return 0;
}
