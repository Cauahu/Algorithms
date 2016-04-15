#include <iostream>
#include <algorithm>
using namespace std;
/*
    寻找满足条件的两个数，先将原数组排序，时间复杂度O(NlogN)，在设置两个游标，一个从头，一个从尾，
    计算两个游标之和，若等于sum则返回，小于sum则头游标前进，大于sum则尾游标后退。
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
    return 0;。
}
