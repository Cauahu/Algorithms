/*
���⣺һ����������һ��id���ִ�������������һ�룬���ҳ�����
�⣺ͨ��ÿ��ɾ��������ͬid����ô��ʣ�µ�id�б��У�������id��Ȼ����������һ�롣

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
