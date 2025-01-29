#include <iostream> 

int fib(int n) {
    if(n<=1) return n;

    return fib(n-1) + fib(n-2);
}

int fibTail(int len, int l, int r) {
    if(len<1) return l;

    return fibTail(len-1, r, l+r);
}

int main() {
    int n = 19;
    for(int i=0; i<n; i++) {
        std::cout << fib(i) << " ";
    }
    std::cout << '\n';

    for(int i=0; i<n; i++) {
        std::cout << fibTail(i, 0, 1) << " ";
    }
    std::cout << '\n';

    return 0;
}