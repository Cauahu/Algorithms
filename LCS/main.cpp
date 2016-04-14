/*
一、最长公共子序列--LCS（Longest Common Subsequence）
   （1）概念：一个字符串的子序列是指从该字符串中去掉任意多个字符后剩下的字符在不改变顺序的情况下组成的新字符串。例如cnblogs和belong的公共子序列为blog，仔细想想我们可以发现其实最长公共子序列的个数不是唯一的，有可能会有两个以上，但长度一定是唯一的。

    （2）解决方案：动态划归。
     两个字符串str1和str2，长度分别为m和n，创建一个二维数组LCS[m,n]用于记录str1[m]和str2[n]的LCS的长度。m和n分别从0开始，如果str1[m] == str2[n] ，则LCS[m,n] = LCS[m-1,n-1] + 1，若str1[m] ！= str2[n] ，则LCS[m,n] = MAX（LCS[m,n-1]，LCS[m-1,n]），如此下去即可。
            0                                     若m=0或n=0；
LCS[m,n] =  LCS[m-1,n-1]                          若m,n>0且str1[m]==str2[n];
            MAX(LCS[m,n-1], LCS[m-1, n])          若m,n>0且str1[m]!=str2[n];

二、最长公共子串--LCS（Longest Common Substring）
    （1）概念：两个字符串的最长公共子串是指两个字符串的子串中长度最长且相等的子串。
    （2）解决方案：该问题是特殊的最长公共子序列问题，它不单要求下标的序列递增，还要求每次下标的增量为1。
    所以状态转移方程为：
              0                     若m=0或n=0；
    LCS[m,n]  LCS[m-1,n-1] + 1      若m,n>0且str1[m]==str2[n];
              0                     若m,n>0且str1[m]!=str2[n];
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void LCSubsequence(string a, string b)
{
    int lena = a.size(), lenb = b.size();
    const char * ac = a.c_str(), * bc = b.c_str();
    int LCS[lena+1][lenb+1];        //比a，b字符串的长度大1，方便存储计算
    memset(LCS,0,sizeof(LCS));
    for(int i=1;i<=lena;i++)
    {
        for(int j=1;j<=lenb;j++)
        {
            if(ac[i-1] == bc[j-1])      //比较的是a[i-1][j-1]
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
                LCS[i][j] = (LCS[i-1][j]>LCS[i][j-1]?LCS[i-1][j]:LCS[i][j-1]);
        }
        cout << endl;
    }
    cout << "\nLCS:" << LCS[lena][lenb];
}


void LCSubstring(string a, string b)
{
    const char *ac = a.c_str(), *bc = b.c_str();
    int lena = a.size(), lenb = b.size();
    int LCS[lena+1][lenb+1], max = 0, max_x, max_y ;
    memset(LCS, 0, sizeof(LCS));
    for(int i=1;i<=lena;i++)
    {
        for(int j=1;j<=lenb;j++)
        {
            if(ac[i-1] == bc[j-1])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = 0;
            //max = (LCS[i][j]>max?LCS[i][j]:max);
            if(LCS[i][j]>max)
            {
                max = LCS[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }
    cout << "LCS:" << max << endl;
    while(LCS[max_x][max_y])//打印输出
    {
        cout << ac[max_x-1];
        --max_x;
        --max_y;
    }


}

int main()
{
    string a = "shaohui";
    string b = "ahui";
    //LCSubsequence(a,b);
    LCSubstring(a, b);
    return 0;
}
