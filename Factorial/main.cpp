/*
��Ŀ��1.����һ������N����ôN�Ľ׳�N!ĩβ�ж��ٸ�0��
      2.��N!�Ķ����Ʊ�ʾ�����λ1��λ�ã�
�⣺1.����Ŀ����Ҫ����������N!��ֵ�����ǿ���ֱ�Ӵ���Щ������ܵõ�10�����ǣ�����ͱ�ü��ˡ�
    ����10=2*5������N!=2^x * 5^y * k^z����������M=min(x,y),��һ��x���ڵ���y�ģ���Ϊ�ܱ�2�����������ֵ�Ƶ�ʱ��ܱ�5���������ߵö࣬
    ����M=y��
    2.�������ʵ���ϵ�ͬ����N!����������2�ĸ������𰸵���N!����������2�ĸ�����1��
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


void one2(int N)//N���溬��m��5�������Ϊ5^m����ʽ��
{
    int num = 0;
    while(N)
    {
        num += N/5;
        N /= 5;
    }
}

void lowestOne(int N)//N���溬��m��2��������2^m����ʽ��
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
