// 
// Kent State University
// CS 23001 - J. Maletic
//
// Part of lab 6 on dynamic memory
//
// Memory allocation and array bounds checking
//
// C/C++ does not check array bounds, so accessing an element of an
//    array outside of its defined size results in Undefined Behavior
//
// TO COMPILE: clang++ -Wall array_bounds_check.cpp -o bounds_check
// TO RUN: ./bounds_check
//           Then enter a postivie interger value at the prompt
//
// Instructions:
//   Read the code.  Then run the program multiple times.  Examing the output.
//   If on wasp/hornet use values of 10, 16, 32, 33, 40
//   If on a Mac use values of 10 16, 17, 20
//
//   What is wrong with this code?
//  the code can write outside of the size 5 bounds overriding metadata.
//
//   Why is no error raised?
//  because c++ allows this action to take place and expectsthe user to not make this mistake.
//
//   How many bytes are between the start of str1 and str2?
//  you can find the number by taking the adresses of both strs and doing this equation, (str2 - str1) * 4
//
//   How could you test for this logical error?
//  using valgrind to compile
//
//   How could you prevent this type of error?
//  checking the bounds and not going outside of it
//
//   Include the delete[] at then end and recompile, what changes?
//  no more leaks


#include <iostream>


int main () {
    char *str1 = new char[5];     //Allocate two arrays on the heap
    char *str2 = new char[20];
    int n=0;

    std::cout  << "str1->char[5]" << std::endl;
    std::cout  << "str2->char[20]" << std::endl;
    std::cout  << "Enter positive integer value: ";  // n > 0
    std::cin >> n;

    std::cout  << "Write to array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Write to str1[0...n-1]
        str1[i] = 'X';
        std::cout << "str1[" << i << "] = 'X'" << std::endl;
    }

    std::cout  << "Contents of array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Print str1[0...n-1]
        std::cout << "str1[" << i << "] == " << "|" <<  str1[i] << "|" << std::endl;
    }

    std::cout  << "Contents of array str2:" << std::endl;
    for (int i = 0; i < 20; ++i) {    //Print str2[0...19]
        std::cout << "str2[" << i << "] == " << "|" <<  str2[i] << "|" << std::endl;
    }

    delete[] str1;
    delete[] str2;

    return 0;
}

