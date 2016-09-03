#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

/*
查找矩形
Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 65536/65536 K (Java/Others)
Problem Description:
对于一组水平线段及垂直线段，共有n条，已知其中必定存在一个若干条线段组成的矩形，输出这个矩形的左下角和右上角点，定义左下角点有最小的x值和y值，右上角点有最大的x值和y值。
线段可以重合，线段必须恰好能组成矩形，即线段不能头或尾部超出矩阵边界，如下图：

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
小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
做取出队头的值操作的时候，并不弹出当前队头。
小明同学发现，这段程序恰好按顺序输出了1,2,3,...,n。现在小明想让你构造出原始的队列，你能做到吗？

样例输入
4
1
2
5
10
样例输出
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

    while(!Q.empty())              //队列不空，执行循环
    {
        int x=Q.front();            //取出当前队头的值x
        Q.pop();                 //弹出当前队头
        Q.push(x);               //把x放入队尾
        x=Q.front();              //取出这时候队头的值
        printf("%d\n",x);          //输出x
        Q.pop();                 //弹出这时候的队头
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
第一行一个数T(T<=100)，表示数据组数。对于每组数据，第一行两个数n,k(1<=n,k<=100)，
接下来一行有2n个数a1,a2,...,a2n(1<=ai<=1000000000)。表示原始牌组从上到下的序列。

输出
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。

样例输入
3
3 1
1 2 3 4 5 6
3 2
1 2 3 4 5 6
2 2
1 1 1 1
样例输出
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











