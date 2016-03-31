/*
����������
    �����еĽ�˧ֻ�����Լ�3*3�ĸ������˶�������˧��������棬�����˧���кϷ�λ�á�Ҫ�������ֻ��ʹ��һ��������
���������ͨ��һ��unsigned char����λ������ɡ�
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

void solvesecend()//����2
{
    unsigned char i = 81;
    while(i--)
    {
        if(i/9%3 != i%9%3)
            cout << "A:" << i/9+1 << ",B: " << i%9+1 << endl;
    }
}
��
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
