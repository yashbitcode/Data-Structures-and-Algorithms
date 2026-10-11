#include <iostream>
using namespace std;

int factorial(int n) {
    if(n <= 1) return 1;

    return n * factorial(n - 1);
}

int fibonnaci(int n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;

    return fibonnaci(n - 1) + fibonnaci(n - 2);
}

int main() {
    cout << fibonnaci(40) << endl;
    // cout << factorial(5) << endl;
}