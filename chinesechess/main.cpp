/*
问题描述：
    象棋中的将帅只能在自己3*3的格子中运动，但将帅不能面对面，输出将帅所有合法位置。要求代码中只能使用一个变量。
解决方法：通过一个unsigned char的移位操作完成。
*/

#include <iostream>
#include <cstdio>

using namespace std;

#define FULLMASK 255//11111111
#define HALF_BITS_LENGTH 4
#define LMASK (FULLMASK << HALF_BITS_LENGTH)//11110000
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)//00001111
#define LSET(b,n) (b = (b&RMASK)^(n << HALF_BITS_LENGTH))
#define RSET(b,n) (b = (b&LMASK)^n)
#define LGET(b) ((b&LMASK) >> HALF_BITS_LENGTH)
#define RGET(b) (b&RMASK)
#define GRIDW 3

unsigned char b;

void solvesecend()//方法2
{
    unsigned char i = 81;
    while(i--)
    {
        if(i/9%3 != i%9%3)
            cout << "A:" << i/9+1 << ",B: " << i%9+1 << endl;
    }
}
·
int main()
{
    for(LSET(b,1);LGET(b)<=GRIDW*GRIDW;LSET(b,(LGET(b)+1)))
    {
        for(RSET(b,1);RGET(b)<=GRIDW*GRIDW;RSET(b,(RGET(b)+1)))
        {
            if(LGET(b)%GRIDW != RGET(b)%GRIDW)
                cout << "A:" << LGET(b) << ",B:" << RGET(b) << "\t";
        }
        cout << endl;
    }
    solvesecend();
    return 0;
}
