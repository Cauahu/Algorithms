/*
���⣺�ҳ�һ������������k������
�ⷨ��һ������N�����洢������S�У����Ǵ�����S����ҳ�һ��Ԫ��X��������ֳ�Ϊ��������Sa��Sb��Sa��Ԫ�ش��ڵ���X��Sb�е�Ԫ��С��X��
�������ֿ����ԣ�1.Sa��Ԫ�صĸ���С��k��Sa�����е����ĺ�Sb������k-|Sa|��Ԫ�ؾ���S������k������
                2.Sa�еĸ������ڻ����k���򷵻�Sa������k��Ԫ�ء�
    ƽ��ʱ�临�Ӷ�O(N*logk)��
    �������ѣ�ͨ������k��С�����������ƽ��ʱ�临�Ӷ�O(N*logk)��
*/

#include <iostream>
#include <vector>

using namespace std;

{
    void adjustment(int *a, int k)
    {
        int cur = 1;
        while(2*cur+1 <= k)
        {

        }
    }
    void minheap(int * S, int k)
    {

    }
}

{//����һ��


void Partition(vector<int> S, vector<int> &Sa, vector<int> &Sb )
{
    int p = S.front();
    for(int i=1;i<S.size();i++)
    {
        if(S[i] > p)
            Sa.push_back(S[i]);
        else
            Sb.push_back(S[i]);
    }
    Sa.size() < Sb.size()? Sa.push_back(p):Sb.push_back(p);
}

vector<int> Append(vector<int> a,vector<int> b)
{
    while(!b.empty())
    {
        a.push_back(b.back());
        b.pop_back();
    }
    return a;
}
}

vector<int> Kbig(vector<int> S, int k)
{
    if(k <= 0)//kС��0ʱ���ؿ�
    {
        vector<int> temp;
        return temp ;
    }
    if(S.size() <= k)//S�ĳ���С�ڵ���k�򷵻�S���ɡ�
        return S;
    else
    {
        vector<int> Sa, Sb;
        Partition(S, Sa, Sb);//��S�ֶ�
        //ͳһ������1��Sa�ĸ���С��k�������Sb��Ԫ�أ���С��k���һ�����ؿգ���Ӱ������
        return Append(Kbig(Sa,k),Kbig(Sb,k-Sa.size()));
    }
}

int main()
{
    vector<int> S = {1,2,3,4,5,6,7,8,9};
    vector<int> res = Kbig(S,3);
    while(!res.empty())
    {
        cout << res.back() << " ";
        res.pop_back();
    }
    return 0;
}
