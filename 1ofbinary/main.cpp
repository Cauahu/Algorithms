//题目：二进制中一的个数,三种解法
/*
整数A和B的二进制位中有多少位是不同的？此问题也可以转化成本题目，先将A和B异或，在求结果中1的个数。
*/

#include <iostream>

using namespace std;

void one(int v)//除余操作
{
    int num = 0;
    while(v)
    {
        num += v%2;
        v /= 2;
    }
    cout << num << endl;
}

void two(int v)//移位操作
{
    int num = 0;
    while(v)
    {
        num += v&1;
        v >>= 1;
    }
    cout << num << endl;
}

void three(int v)//通过v&(v-1)直接统计v中1的个数
{
    int num = 0;
    while(v)
    {
        v &= v-1;
        num++;
    }
    cout << num << endl;
}

int main()
{
    one(161);
    two(161);
    three(161);

    return 0;
}
