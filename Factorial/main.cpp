/*
题目：1.给定一个整数N，那么N的阶乘N!末尾有多少个0？
      2.求N!的二进制表示中最低位1的位置？
解：1.本题目不需要计算完整的N!的值，我们可以直接从哪些数相乘能得到10来考虑，问题就变得简单了。
    由于10=2*5，所以N!=2^x * 5^y * k^z。于是最后的M=min(x,y),进一步x大于等于y的，因为能被2整除的数出现的频率比能被5整除的数高得多，
    所以M=y。
    2.这个问题实际上等同于求N!含有质因数2的个数，答案等于N!含有质因数2的个数加1。
*/

#include <iostream>

using namespace std;

void one1(int N)
{
    int num = 0;
    for(int i=1;i<=N;i++)
    {
        int j = i;
        while(j%5 == 0)
        {
            num++;
            j /= 5;
        }
    }
    cout << num << endl;
}


void one2(int N)//N里面含有m个5，最后会成为5^m的形式。
{
    int num = 0;
    while(N)
    {
        num += N/5;
        N /= 5;
    }
}

void lowestOne(int N)//N里面含有m个2，最后会变成2^m的形式。
{
    int sum = 0;
    while(N)
    {
        N >>= 1;
        sum += N;
    }
    cout << sum << endl;
}

int main()
{
    one1(3);
    lowestOne(5);
    return 0;
}
