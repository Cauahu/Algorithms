#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
/*
设计一个算法，把一个含有N个元素的数组循环右移K位，要求时间复杂度为O(N)，且只允许使用两个附加变量。
K有可能大于N，但右移K位的情形，跟右移K1=K%N的情形一样。
例如原数组序列为abcd1234，要求变换后变为1234abcd，即循环右移了4位，可以通过逆序排列完成操作。
1.逆序排列abcd：abcd1234 -> dcba1234
2.逆序排列1234: dcba1234 -> dcba4321
3.逆序排列全部：dcba4321 -> 1234abcd
*/
    char a[] = "abcd1234";
    int i=0;
    while(a[i++]!='\0');
    int N;
    cin >> N;
    while(N!=0)
    {
        N %= i;
        reverse(a,a+i-N-1);
        cout << a << endl ;
        reverse(a+i-N-1,a+i-1);
        cout << a << endl ;
        reverse(a,a+i-1);
        cout << a << endl << endl << endl ;
    }
    return 0;
}
