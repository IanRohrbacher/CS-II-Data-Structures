#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    std::ifstream file("data1-1.txt");
    //std::ifstream file("data1-2.txt");

    if(!file.is_open()) {
        std::cout << "Unable To Open File\n";
    }
    while(!file.eof()) {
        bigint firstNumber, secondNumber;
        file >> firstNumber;
        file >> secondNumber;
        if(!file.eof()) {
            std::cout << "Num1: " << firstNumber << '\n';
            std::cout << "Num2: " << secondNumber << '\n';
            std::cout << "Result: " << firstNumber + secondNumber << '\n';
        }
    }

    file.close();
    return 0;
}