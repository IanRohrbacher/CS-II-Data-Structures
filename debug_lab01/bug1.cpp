///////////////////////////////////////////////////////////////////////////
//  bug1.cpp
//   
// 
//   Created by Maletic on 9/9/13.
// 
//   This code prints out a sets of random numbers, no duplicates per set.
//
//   There is a bug in this code.  It compiles but seems to get into an infinit loop.
//   Find the bug.
//
//   Step 1: Compile the program clang++ -Wall bug1.cpp -o buggy
//           Run it ./buggy  ctrl c to break it.
//   Step 2: Read over the code and figure out what it does a bit.
//           Insert print statements into the different loops to 
//           determine where the infinite loop is occurring.
//           Start in the main and work down the call stack.
//   Step 3: Once you figure out what loop is the problem try to 
//           figure out what it is supposed to do and why its broken.
//   Step 4: Make the fix and compile/run the program
//   Step 5: Does it work?  



#include <iostream>
#include <cstdlib>

const int MAX             = 6;
const int SIZE_OF_SAMPLES = 3;
const int REP             = 5;

bool inArray     (int[], int, int  );
void UniqRandInt (int,   int, int[]);

int main() {
    int arr[SIZE_OF_SAMPLES];
    srand(9809);  //Seed random number generator.

    //std::cerr << "Error 1\n";
    for (int i = 0; i < REP; i++) {
        //std::cerr << "Error 2\n";
        //std::cerr << "main i:" << i << '\n';
        UniqRandInt(MAX, SIZE_OF_SAMPLES, arr);
        //std::cerr << "Error 3\n";
        for(int j = 0; j < SIZE_OF_SAMPLES; j++) {
            //std::cerr << "Error 4\n";
            //std::cerr << "main j:" << j << '\n';
            std::cout << arr[j] << " ";
            //std::cerr << "Error 5\n";
        }
        //std::cerr << "Error 6\n";
        std::cout << std::endl;
        //std::cerr << "Error 7\n";
    }
    //std::cerr << "Error 8\n";
    return 0;
}

// result[n] will be initialized with a set of random numbers, no duplicates
//           Values between 0 and max.
// 
void UniqRandInt(int max, int n, int result[]) {
    int cntr = 0, r;

    while(cntr < n) {
        //std::cerr << "Error 2 sub 1\n";
        r = rand();  //Get random number
        //std::cerr << r << "\n";
        r = r % (max + 1);
        //std::cerr << "Error 2 sub 2\n";
        //std::cerr << r << "\n";
        if (!inArray(result, cntr, r)) {
            //std::cerr << "Error 2 sub 3\n";
            result[cntr] =  r;
            cntr++;
            //std::cerr << "Error 2 sub 4\n";
        }
    }
    //std::cerr << "Error 2 sub 5\n";
    return;
}

// Check if x is included in array[] of arrSize.
// Returns: 1 if x is a member
//           0 if x is not a member
// 
bool inArray(int array[], int arrSize, int x) {
    //std::cerr << "RAN\n";
    for (int i = 0; i < arrSize; ++i) {
        //std::cerr << "inArray i:" << i << " | " << "array[i]" << array[i] << "\n";
        if (array[i] == x) {
            return true;
        }
    }
    return false;
}
