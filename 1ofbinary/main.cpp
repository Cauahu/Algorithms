//��Ŀ����������һ�ĸ���,���ֽⷨ
/*
����A��B�Ķ�����λ���ж���λ�ǲ�ͬ�ģ�������Ҳ����ת���ɱ���Ŀ���Ƚ�A��B�����������1�ĸ�����
*/

#include <iostream>

using namespace std;

void one(int v)//�������
{
    int num = 0;
    while(v)
    {
        num += v%2;
        v /= 2;
    }
    cout << num << endl;
}

void two(int v)//��λ����
{
    int num = 0;
    while(v)
    {
        num += v&1;
        v >>= 1;
    }
    cout << num << endl;
}

void three(int v)//ͨ��v&(v-1)ֱ��ͳ��v��1�ĸ���
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
