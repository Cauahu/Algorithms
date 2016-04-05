#include <iostream>
#include <string.h>
using namespace std;

int alrea[100];
//递推关系式的优化：用一个数组存储所有已经计算过的项,用空间换取时间。
int functionone(int n)
{
    if(n<=0)
    {
        cout << "alrea[0]:" << alrea[0] << endl;
        return alrea[0];
    }
    else if(n==1)
    {
        cout << "alrea[1]:" << alrea[1] << endl;
        return alrea[1];
    }
    else if(alrea[n]!=-1)
    {
        cout << "alrea[" << n <<"]:" << alrea[n] << endl;
        return alrea[n];
    }
    else
    {
        cout << "function" << endl;
        int temp = functionone(n-1)+functionone(n-2);
        alrea[n] = temp;
        return temp;
    }
}


int main()
{
    memset(alrea,-1,sizeof(alrea));
    alrea[0] = 0;
    alrea[1] = 1;
    cout << functionone(10) << endl;
    return 0;
}
