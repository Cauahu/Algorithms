#include <iostream>
#include <queue>

using namespace std;

void selectsort(int *a, int n)
{
    /*
    ÿһ�˴Ӵ����������Ԫ����ѡ����С������󣩵�һ��Ԫ�أ�˳��������ź�������е����
    ֱ��ȫ�������������Ԫ�����ꡣ ѡ�������ǲ��ȶ������򷽷����㷨���Ӷ���O(n ^2 )��
    */

    for(int i=0;i<n-1;i++)
    {
        int m = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[m] > a[j])
                m = j;
        }
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }

}

void insertsort(int *a ,int n)
{
    /*
    ÿ�δ��������ȡ����һ��Ԫ�أ��������뵽�����ĺ���λ�ã�ʹ�������Ȼ����
    ֱ�Ӳ����������ȶ��ġ��㷨ʱ�临�Ӷ���O(n ^2)
    */
    for(int i=1;i<n;i++)
    {
        int temp = a[i];
        int j=i;
        for(;temp<a[j-1];j--)
            a[j] = a[j-1];
        a[j] = temp;
    }
}

void radixsort(int *a, int n)
{
    /*

    */
    vector<queue<int>> RAD(10);
    bool flag = false;
    int carry = 10;
    int r = 2;
    while(r--)
    {
        flag = true;
        for(int i=0;i<n;i++)
        {
            //if((a[i]/carry)!=0)
             //   flag = false;
             int cur = a[i]%carry/(carry/10);
            RAD[cur].push(a[i]);
        }
        for(int i=0,j=0;i<10;i++)
        {
            while(!RAD[i].empty())
            {
                 a[j++] = RAD[i].front();
                 RAD[i].pop();
            }
        }
        carry *= 10;
    }
}

int main()
{
    //int a[] = {6,2,7,4,1,8,3,5};
    //selectsort(a,8);
    int a[] = {73, 22, 93, 43, 55, 14, 28, 65};
    radixsort(a,8);
    for(int i=0;i<8;i++)
        cout << a[i] << " ";
    return 0;
}
