#include <iostream>

using namespace std;

void questionone(int n)
{
    /*
    ����1��дһ�����򣬶���һ��������������п��ܵ�������Ȼ��֮�͵���ʽ��
    �⣺num = a + a+1 + a+2 + a+3 + ...... + a+k-2 + a+k-1 = k(a+a+k-1)/2
            = ka + k(k-1)/2
        k��������a������������k(k-1)/2Ҳ��������
    */
    int k,i,temp = 0;
    int flag = 1;//od�����ж�k����ż�ԣ�flag�����ж��Ƿ����a
    for(k=2;n>temp;k++)
    {
        temp = k*(k-1)/2;
        if((n-temp)%k==0)
        {
            flag = 0;
            i = (n-temp)/k;
            int cur = k-1;
            cout << n << " = ";
            while(cur--)
                cout << i++ << "+";
            cout << i << ";" <<endl;
        }
    }
    if(flag)
        cout << n << "���ܱ�ʾΪ�������ֺ͵���ʽ��" << endl;
}

void questiontwo()
{
    /*
    ����2����Щ���ܱ�ʾΪ�������ֺ͵���ʽ��������ʲô���ɣ�
    �⣺
    num =  = ka + k(k-1)/2 = k(2i+k-1)/2,�ɴ˿�֪2i��ż������kΪ������k-1Ϊż������X=(2i+k-1)Ϊż��������num=k*X(����*ż��)��
    ��kΪż������(2i+k-1)Ϊ����������num=(����*ż��)��
    ����num������д��������ż���ĳ˻�������ֻ��2^n���ܹ�д���������ֺ͵���ʽ��
    */
}


int main()
{
    questionone(9);
    questionone(8);
    questionone(32);
    return 0;
}
