/*
最长回文子串（Longest Plalindrome Substring）是指字符串str的字串中正着读和倒着读都一样的子串。
有四种方法：分别为（1）暴力法（2）动态规划（3）中心法（4）中心扩展，下面分别实现出来。

*/

#include <iostream>
#include <string>
#include <string.h>




using namespace std;

void findLPS_violent(string str)//暴力法
{
    int len = str.size(), maxlensub = 0, sub_s = 0, sub_e = 0;
    for(int i=0;i<len-1;i++)//起始字符
    {
        for(int j=i+1;j<len;j++)//终止字符
        {
            int s_char = i, e_char = j;
            while(s_char<e_char)        //比较判断是否是回文字符
            {
                if(str.at(s_char) != str.at(e_char))
                    break;
                s_char++;
                e_char--;
            }
            if(s_char>=e_char&&j-i+1>maxlensub)
            {
                maxlensub = j-i+1;
                sub_s = i;
                sub_e = j;
            }
        }
    }
    cout << "LPS:" << str.substr(sub_s, sub_e) << " i:" << sub_s << " j:" << sub_e << " length:" << maxlensub << endl;
}

void findLPS_DP(string str)//动态规划，先从小长度的子串开始，慢慢递归到大长度子串
{
    int len = str.size(), P[len][len];
    memset(P, 0, sizeof(P));
    int maxlensub = 0, sub_s = 0, sub_e = 0;
    for(int i=0;i<len;i++)
    {
        P[i][i] = 1;
        if(i<len-1&&str.at(i) == str.at(i+1))
            P[i][i+1] = 1;
    }
    for(int sublen=3;sublen<=len;sublen++)//子串长度
    {
        for(int i=0;i<=len-sublen;i++)//子串起始地址
        {
            int j = i+sublen-1;
            if(str.at(i) == str.at(j))
            {
                P[i][j] = P[i+1][j-1];
                if(P[i][j] && maxlensub < sublen)
                {
                    maxlensub = sublen;
                    sub_s = i;
                    sub_e = j;
                }
            }
            else
                P[i][j] = 0;
        }
    }
    cout << "LPS:" << str.substr(sub_s, sub_e) << " i:" << sub_s << " j:" << sub_e << " length:" << maxlensub << endl;
}

void _centerextion(string &str,int i, int j, int &maxsublen, int &sub_s)//中心扩展法的内部实现方法
{
    int len = str.size();
    while(i>=0&&j<len&&str.at(i)==str.at(j))
    {
        if(j-i+1 > maxsublen)
        {
            maxsublen = j-i+1;
            sub_s = i;
        }
        i--;
        j++;
    }
}

void findLPS_centerextion(string str)//中心扩展法
{
    int len = str.size(), maxsublen=0, sub_s;
    for(int i=0;i<len;i++)//长度为偶数
    {
        _centerextion(str, i-1, i+1, maxsublen, sub_s);
    }
    for(int i=0;i<len;i++)//长度为偶数
    {
        _centerextion(str, i, i+1, maxsublen, sub_s);
    }
    cout << "LPS:" << str.substr(sub_s, sub_s+maxsublen) << " i:" << sub_s << " j:" << sub_s+maxsublen-1 << " length:" << maxsublen << endl;
}

void findLPS_manacher(string str)//manacher方法
{
    int maxrange=0, id=0, len=str.size(), maxsublen = 0, sub_s ;
    int *P = new int[len];
    memset(P,0,len*sizeof(int));
    for(int i=0;i<len;i++)
    {
        if(maxrange>i)          //manacher算法中心思想
            P[i] = (P[2*id-i]<maxrange-i?P[2*id-i]:maxrange-i);
        else
            P[i] = 1;
        while(i>P[i]&&i+P[i]<len&&str.at(i-P[i])==str.at(i+P[i]))       //扩张回文半径
            P[i]++;
        if(i+P[i] > maxrange)   //当前点超出范围，则移动中心点
        {
            maxrange = i + P[i];
            id = i;
        }
        if(maxsublen < P[i])//记录最大回文串长度
        {
            maxsublen = P[i];
            sub_s = i;
        }
    }
    cout << maxsublen << endl;
}


int main()
{
    string s = "abcba";
    //findLPS_violent(s);
    //findLPS_DP(s);
    //findLPS_centerextion(s);
    int len = s.size();
    for(int i=0;i<2*len+1;i+=2)//将字符串变为总是奇数。
        s.insert(i, "#");
    findLPS_manacher(s);
    return 0;
}
