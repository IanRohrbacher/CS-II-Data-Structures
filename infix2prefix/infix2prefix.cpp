#include <fstream>
#include <vector>
#include <iostream>
#include "../assembler/stack.hpp"
#include "../string/string.hpp"



int main(int argc, char const* argv[])
{
    std::ifstream file("data3-1.txt");
    
	if (!file.is_open()) {
		std::cout << "Unable To Open File\n";
	} else {
        stack<String> myStack;
        String left, right, sign, current;
        char tempChar[100];

        while (!file.eof()) {
            file >> tempChar;
            current = String(tempChar);

            if (file.eof()) {
                break;
            }

            if (current == ";") {
                std::cout << myStack.top();
                std::cout << ";";
                std::cout << std::endl;
                myStack = stack<String>();
            } else if (current == ")") {
                right = myStack.pop();
                sign = myStack.pop();
                left = myStack.pop();
                myStack.push(sign + left + right);
            } else {
                if (current != "(") {
                    myStack.push(current + ' ');
                }
            }
        }
    }

    file.close();

    return 0;
}
