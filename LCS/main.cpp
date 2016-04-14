/*
һ�������������--LCS��Longest Common Subsequence��
   ��1�����һ���ַ�������������ָ�Ӹ��ַ�����ȥ���������ַ���ʣ�µ��ַ��ڲ��ı�˳����������ɵ����ַ���������cnblogs��belong�Ĺ���������Ϊblog����ϸ�������ǿ��Է�����ʵ����������еĸ�������Ψһ�ģ��п��ܻ����������ϣ�������һ����Ψһ�ġ�

    ��2�������������̬���顣
     �����ַ���str1��str2�����ȷֱ�Ϊm��n������һ����ά����LCS[m,n]���ڼ�¼str1[m]��str2[n]��LCS�ĳ��ȡ�m��n�ֱ��0��ʼ�����str1[m] == str2[n] ����LCS[m,n] = LCS[m-1,n-1] + 1����str1[m] ��= str2[n] ����LCS[m,n] = MAX��LCS[m,n-1]��LCS[m-1,n]���������ȥ���ɡ�
            0                                     ��m=0��n=0��
LCS[m,n] =  LCS[m-1,n-1]                          ��m,n>0��str1[m]==str2[n];
            MAX(LCS[m,n-1], LCS[m-1, n])          ��m,n>0��str1[m]!=str2[n];

����������Ӵ�--LCS��Longest Common Substring��
    ��1����������ַ�����������Ӵ���ָ�����ַ������Ӵ��г��������ȵ��Ӵ���
    ��2��������������������������������������⣬������Ҫ���±�����е�������Ҫ��ÿ���±������Ϊ1��
    ����״̬ת�Ʒ���Ϊ��
              0                     ��m=0��n=0��
    LCS[m,n]  LCS[m-1,n-1] + 1      ��m,n>0��str1[m]==str2[n];
              0                     ��m,n>0��str1[m]!=str2[n];
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void LCSubsequence(string a, string b)
{
    int lena = a.size(), lenb = b.size();
    const char * ac = a.c_str(), * bc = b.c_str();
    int LCS[lena+1][lenb+1];        //��a��b�ַ����ĳ��ȴ�1������洢����
    memset(LCS,0,sizeof(LCS));
    for(int i=1;i<=lena;i++)
    {
        for(int j=1;j<=lenb;j++)
        {
            if(ac[i-1] == bc[j-1])      //�Ƚϵ���a[i-1][j-1]
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
    while(LCS[max_x][max_y])//��ӡ���
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
