#include <iostream>
#include <algorithm>
using namespace std;
/*
    Ѱ���������������������Ƚ�ԭ��������ʱ�临�Ӷ�O(NlogN)�������������α꣬һ����ͷ��һ����β��
    ���������α�֮�ͣ�������sum�򷵻أ�С��sum��ͷ�α�ǰ��������sum��β�α���ˡ�
*/
void findtwosum(int *a,int sum,int &b,int &e)
{
    for(b=0,e=6;b!=e;)
    {
        if(a[b]+a[e] == sum)
        {
            cout << b << " " << e << endl;
            b++;
            e--;
        }
        else if(a[b]+a[e] < sum)
            b++;
        else
            e--;
    }
}

int main()
{
    int a[] = {5,6,1,4,7,9,8};
    sort(a,a+7);
    int b=-1,e=-1;
    findtwosum(a,10,b,e);
    return 0;��
}
