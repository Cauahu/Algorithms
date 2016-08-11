#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMissing(vector<vector<int> > vec, int n)
{
    for(int i=0;i<n;++i)
    {
        if((i % 2) != vec[i][0])
            return i;
    }
    return n;
}

int main()
{

    return 0;
}
