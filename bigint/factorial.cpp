#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
    bigint four(4);
    bigint five(5);
    bigint six(6);
    bigint ten(10);
    bigint tenfive(15);
    bigint twoten(20);
    bigint threeten(30);
    bigint fiveten(50);
    bigint big(100);
    bigint zero(0);

    std::cout << four << " Factoria is " << four.nfact() << " with " << four.trailingZero() << " leading zeros" << '\n';
    std::cout << five << " Factoria is " << five.nfact() << " with " << five.trailingZero() << " leading zeros" << '\n';
    std::cout << six << " Factoria is " << six.nfact() << " with " << six.trailingZero() << " leading zeros" << '\n';
    std::cout << ten << " Factoria is " << ten.nfact() << " with " << ten.trailingZero() << " leading zeros" << '\n';
    std::cout << tenfive << " Factoria is " << tenfive.nfact() << " with " << tenfive.trailingZero() << " leading zeros" << '\n';
    std::cout << twoten << " Factoria is " << twoten.nfact() << " with " << twoten.trailingZero() << " leading zeros" << '\n';
    std::cout << threeten << " Factoria is " << threeten.nfact() << " with " << threeten.trailingZero() << " leading zeros" << '\n';
    std::cout << fiveten << " Factoria is " << fiveten.nfact() << " with " << fiveten.trailingZero() << " leading zeros" << '\n';
    std::cout << big << " Factoria is " << big.nfact() << " with " << big.trailingZero() << " leading zeros" << '\n';
    std::cout << zero << " Factoria is " << zero.nfact() << " with " << zero.trailingZero() << " leading zeros" << '\n';

    /*
    How many trailing zero's are there on 100! ?
    24

    Implement a funciton/method to count the trailing 0's of a bigint. Give the output and a description of how you calculated the answer.
    I took my function leadingZero and looped from the start instead of the bottom.

    Give a short write up about how one can mathematically figure out how many trailing zeros are on a given number (besides coding it up).    
    We can solve this by taking the number x and divide by 5^(n) starting at n=1 untill the result is not a whole number. Then we add the
    whole numbers together to get the result. So with 100 you take 100/5^1 + 100/5^2 + 100/5^3 or 20 + 4 + 0.8. Then add the whole numbers
    20 and 4 to get 24.
    */
   
    return 0;
}
