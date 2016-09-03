#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

/*
���Ҿ���
Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 65536/65536 K (Java/Others)
Problem Description:
����һ��ˮƽ�߶μ���ֱ�߶Σ�����n������֪���бض�����һ���������߶���ɵľ��Σ����������ε����½Ǻ����Ͻǵ㣬�������½ǵ�����С��xֵ��yֵ�����Ͻǵ�������xֵ��yֵ��
�߶ο����غϣ��߶α���ǡ������ɾ��Σ����߶β���ͷ��β����������߽磬����ͼ��

4
0 0 0 1
0 0 1 0
0 1 1 1
1 0 1 1



struct Node{
int x1;
int y1;
int x2;
int y2;
};

void findjuxing(Node *node, int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(node[i].x2 == node[j].x1 && node[i].y2 == node[j].y1)
            {
                for(int a=0;a<n;++a)
                {
                    if(node[j].x2 == node[a].x1 && node[j].y2 == node[a].y1)
                    {
                        for(int b=0;b<n;++b)
                        {
                            if(node[a].x2 == node[b].x1 && node[a].y2 == node[b].y1
                               && node[b].x2 == node[i].x1 && node[b].y2 == node[i].y1 )
                            {
                                cout << node[i].x1 << " " << node[i].y1 << " ";
                                cout << node[j].x2 << " " << node[j].y2 << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }




}


int main()
{
    int n;
    cin >> n;
    Node *node = new Node[n];
    for(int i=0;i<n;++i)
    {
        cin >> node[i].x1;
        cin >> node[i].y1;
        cin >> node[i].x2;
        cin >> node[i].y2;
    }
    findjuxing(node, n);
    return 0;
}
*/



/*
С��ͬѧ��1��n��n�����ְ���һ����˳�������һ������Q�С��������Զ���Qִ�������³���
��ȡ����ͷ��ֵ������ʱ�򣬲���������ǰ��ͷ��
С��ͬѧ���֣���γ���ǡ�ð�˳�������1,2,3,...,n������С�������㹹���ԭʼ�Ķ��У�����������

��������
4
1
2
5
10
�������
1
2 1
2 1 3
8 1 6 2 10 3 7 4 9 5



int main()
{
    queue<int> Q;
    deque<int> dq;
    Q.push(10);
    Q.push(9);
    Q.push(8);
    Q.push(7);
    Q.push(6);
    Q.push(5);
    Q.push(4);
    Q.push(3);
    Q.push(2);
    Q.push(1);

    while(!Q.empty())              //���в��գ�ִ��ѭ��
    {
        int x=Q.front();            //ȡ����ǰ��ͷ��ֵx
        Q.pop();                 //������ǰ��ͷ
        Q.push(x);               //��x�����β
        x=Q.front();              //ȡ����ʱ���ͷ��ֵ
        printf("%d\n",x);          //���x
        Q.pop();                 //������ʱ��Ķ�ͷ
    }

    while(!dq.empty())
    {
        int x = dq.back();
        dq.pop_back();
        dq.push_front(x);
        x = dq.back();
        cout << x << " ";
        dq.pop_back();
    }

    cout << endl;


}

*/


/*
��һ��һ����T(T<=100)����ʾ��������������ÿ�����ݣ���һ��������n,k(1<=n,k<=100)��
������һ����2n����a1,a2,...,a2n(1<=ai<=1000000000)����ʾԭʼ������ϵ��µ����С�

���
����ÿ�����ݣ����һ�У����յ����С�����֮���ÿո��������Ҫ����ĩ�������Ŀո�

��������
3
3 1
1 2 3 4 5 6
3 2
1 2 3 4 5 6
2 2
1 1 1 1
�������
1 4 2 5 3 6
1 5 4 3 2 6
1 1 1 1

*/

void xipai(vector<int> &vec)
{
    int len = vec.size(), mid = len / 2;
    deque<int> dq1, dq2;
    for(int i=0;i<mid;++i)
        dq1.push_front(vec[i]);

    for(int i=mid;i<len;++i)
        dq2.push_front(vec[i]);

    int i=0;
    while(i < len)
    {
        vec[i++] = dq1.back();
        vec[i++] = dq2.back();
        dq1.pop_back();
        dq2.pop_back();
    }
}


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, k;
        cin >> n >> k;
        n = 2 * n;
        vector<int> vec;
        for(int i=0,x;i<n;++i)
        {
            cin >> x;
            vec.push_back(x);
        }

        for(int i=0;i<k;++i)
            xipai(vec);

        for(int i=0;i<n-1;++i)
            cout << vec[i] << " ";
        cout << vec[n-1];
    }

    return 0;
}











