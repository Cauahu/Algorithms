#include <iostream>

using namespace std;

int exchangeOddEven(int x) {
        // write code here
    int odd = x & 0xAAAAAAAA;
    int even = x & 0x55555555;
    return (odd >> 1) + (even << 1);
}

int main()
{
    cout << exchangeOddEven(-10) << endl;
    return 0;
}
