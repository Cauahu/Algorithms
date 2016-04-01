/*
问题：一个序列中有一个id出现次数超过总数的一半，请找出它。
解：通过每次删除两个不同id，那么，剩下的id列表中，最大次数id依然超过总数的一半。

*/
#include <iostream>

using namespace std;

void findox(int *a, int n)
{
    int result , ntimes = 0;
    for(int i=0;i<n;i++)
    {
        if(ntimes == 0)
        {
            result = a[i];
            ntimes = 1;
        }
        else
        {
            if(result == a[i])
                ntimes++;
            else
                ntimes--;
        }
    }
    cout << result << endl;
}

int main()
{

    return 0;
}
