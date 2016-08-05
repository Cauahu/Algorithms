#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int avergeapple(int n, vector<int> vec)
{
    int sumapple = 0, avg = 0;
    for(int i=0;i<n;++i)
    {
        sumapple +=vec[i];
    }

    if((sumapple % n) != 0)
        return -1;
    avg = sumapple / n;

    int greaterzero = 0;
    for(int i=0;i<n;++i)
    {
        int temp = vec[i] - avg;
        if(temp % 2 != 0)
            return -1;
        if(temp > 0)
            greaterzero += temp;
    }
    return greaterzero / 2;
}

/*
int main()
{
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    cout << avergeapple(n, vec) << endl;

    return 0;
}
*/

