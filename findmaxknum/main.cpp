/*
问题：找出一个序列中最大的k个数。
解法：一、假设N个数存储在数组S中，我们从数组S随机找出一个元素X，把数组分成为两个部分Sa和Sb。Sa中元素大于等于X，Sb中的元素小于X。
则有两种可能性：1.Sa中元素的个数小于k，Sa中所有的数的和Sb中最大的k-|Sa|个元素就是S中最大的k个数。
                2.Sa中的个数大于或等于k，则返回Sa中最大的k个元素。
    平均时间复杂度O(N*logk)。
    二、建堆，通过建立k的小根堆来解决。平均时间复杂度O(N*logk)。
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

{//方法一：


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
    if(k <= 0)//k小于0时返回空
    {
        vector<int> temp;
        return temp ;
    }
    if(S.size() <= k)//S的长度小于等于k则返回S即可。
        return S;
    else
    {
        vector<int> Sa, Sb;
        Partition(S, Sa, Sb);//将S分段
        //统一处理：（1）Sa的个数小于k则需加上Sb中元素，不小于k则后一个返回空，不影响结果。
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
