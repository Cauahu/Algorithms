#include<iostream>
#include<algorithm>

using namespace std;

int resolve(int N, int S, int L)
{
    if(N == 0 || S == 0 || L == 0)
        return 0;

    if(S > L)
        return 0;

    int SongPerCD = 1, tatolsecond = SongPerCD * S + SongPerCD - 1;
    while(tatolsecond < L)
    {
        ++SongPerCD;
        tatolsecond = SongPerCD * S + SongPerCD - 1;
    }
    --SongPerCD;

    if((SongPerCD % 13) == 0)
        --SongPerCD;

    int numofCD = 1;
    while(SongPerCD * numofCD < N)
        ++numofCD;
    int lastnumsong = N - SongPerCD * (numofCD - 1);

    if(lastnumsong % 13 == 0)
        ++numofCD;

    return  numofCD;
}
/*
int main()
{
    int n, m;
    cin >> n >> m;
    int maxvalue = INT_MAX;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int input;
            cin >> input;
            if(input < maxvalue)
                maxvalue = input;
        }
    }
    cout << maxvalue << endl;
    return 0;
}
*/
