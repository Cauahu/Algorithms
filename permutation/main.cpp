#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool nextpermutation(string &str)
{
    int len = str.size();
    if(len == 0 || len == 1)
        return false;
    int i = len - 1;
    while(1)
    {
        int ii = i;
        --i;
        if(str[i] < str[ii])
        {
            int t = len - 1;
            while(str[i] > str[t] )
                --t;
            swap(str[i], str[t]);
            reverse(str.begin()+ii, str.end());
            return true;
        }
        if(i == 0)
        {
            reverse(str.begin(), str.end());
            return false;
        }
    }
}

int main()
{
    string str = "abcd";

    do{
        cout << str << endl;
    }while(nextpermutation(str));

    return 0;
}
