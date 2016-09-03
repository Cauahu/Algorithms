#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "abcdef", s2 = "cd";
    string res = "";
    int loop1 = 0;
    int len1 = s1.length(), len2 = s2.length();

    while(loop1 < len1)
    {
        if(s1.at(loop1) == s2.at(0))
        {
            int i = loop1, j = 0;
            while(j < len2)
            {
                if(s1.at(i) != s2.at(j))
                    break;
                i++;
                j++;

            }
            if(j == len2)
                loop1 = i;
        }
        res += s1.at(loop1++);
    }

    cout << res << endl;

    return 0;
}
