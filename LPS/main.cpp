/*
������Ӵ���Longest Plalindrome Substring����ָ�ַ���str���ִ������Ŷ��͵��Ŷ���һ�����Ӵ���
�����ַ������ֱ�Ϊ��1����������2����̬�滮��3�����ķ���4��������չ������ֱ�ʵ�ֳ�����

*/

#include <iostream>
#include <string>
#include <string.h>




using namespace std;

void findLPS_violent(string str)//������
{
    int len = str.size(), maxlensub = 0, sub_s = 0, sub_e = 0;
    for(int i=0;i<len-1;i++)//��ʼ�ַ�
    {
        for(int j=i+1;j<len;j++)//��ֹ�ַ�
        {
            int s_char = i, e_char = j;
            while(s_char<e_char)        //�Ƚ��ж��Ƿ��ǻ����ַ�
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

void findLPS_DP(string str)//��̬�滮���ȴ�С���ȵ��Ӵ���ʼ�������ݹ鵽�󳤶��Ӵ�
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
    for(int sublen=3;sublen<=len;sublen++)//�Ӵ�����
    {
        for(int i=0;i<=len-sublen;i++)//�Ӵ���ʼ��ַ
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

void _centerextion(string &str,int i, int j, int &maxsublen, int &sub_s)//������չ�����ڲ�ʵ�ַ���
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

void findLPS_centerextion(string str)//������չ��
{
    int len = str.size(), maxsublen=0, sub_s;
    for(int i=0;i<len;i++)//����Ϊż��
    {
        _centerextion(str, i-1, i+1, maxsublen, sub_s);
    }
    for(int i=0;i<len;i++)//����Ϊż��
    {
        _centerextion(str, i, i+1, maxsublen, sub_s);
    }
    cout << "LPS:" << str.substr(sub_s, sub_s+maxsublen) << " i:" << sub_s << " j:" << sub_s+maxsublen-1 << " length:" << maxsublen << endl;
}

void findLPS_manacher(string str)//manacher����
{
    int maxrange=0, id=0, len=str.size(), maxsublen = 0, sub_s ;
    int *P = new int[len];
    memset(P,0,len*sizeof(int));
    for(int i=0;i<len;i++)
    {
        if(maxrange>i)          //manacher�㷨����˼��
            P[i] = (P[2*id-i]<maxrange-i?P[2*id-i]:maxrange-i);
        else
            P[i] = 1;
        while(i>P[i]&&i+P[i]<len&&str.at(i-P[i])==str.at(i+P[i]))       //���Ż��İ뾶
            P[i]++;
        if(i+P[i] > maxrange)   //��ǰ�㳬����Χ�����ƶ����ĵ�
        {
            maxrange = i + P[i];
            id = i;
        }
        if(maxsublen < P[i])//��¼�����Ĵ�����
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
    for(int i=0;i<2*len+1;i+=2)//���ַ�����Ϊ����������
        s.insert(i, "#");
    findLPS_manacher(s);
    return 0;
}
