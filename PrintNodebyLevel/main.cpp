#include <iostream>
#include <vector>

using namespace std;

typedef struct Node  //节点存储格式
{
    int date;
    Node* lchild;
    Node* rchild;
}Node,*PNode;

int pos = 0;

PNode buildtree(int* a, int N)//建立二叉树
{
    if(pos == N-1)
        return NULL;
    if(a[pos] == 0)
    {
        pos++;
        return NULL;
    }

    PNode pnode = new Node;
    pnode->lchild = NULL;
    pnode->rchild = NULL;
    pnode->date = a[pos];
    pos++;
    pnode->lchild = buildtree(a, N);
    pnode->rchild = buildtree(a, N);
    return pnode;
}

void priorder(Node *node)//先序遍历二叉树，主要作用是检查树是否建立完整。
{
    if(node)
    {
        cout << node->date << " ";
        priorder(node->lchild);
        priorder(node->rchild);
    }

}


void printbylevel(PNode pnode)
{
    if(pnode == NULL)
        return;
    vector<PNode> vec;//存储临时节点值
    vector<int> postvec;
    vec.push_back(pnode);
    int cur = 0;
    int last = 1;
    while(cur < vec.size())
    {
        last = vec.size();
        while(cur != last)
        {
            cout << vec[cur]->date << " ";
            postvec.push_back(vec[cur]->date);
            if(vec[cur]->rchild)
                vec.push_back(vec[cur]->rchild);
            if(vec[cur]->lchild)
                vec.push_back(vec[cur]->lchild);
            cur++;
        }
        postvec.push_back(0);
        cout << endl;
    }
    while(postvec.size())
    {
        if(postvec.back())
            cout << postvec.back() << " ";
        else
            cout << endl;
        postvec.pop_back();
    }



}

int main()
{
    int a[] = {1,2,4,0,0,5,7,0,0,8,0,0,3,0,6,0,0};
    PNode Pnode = NULL;
    Pnode = buildtree(a, 17);
    priorder(Pnode);
    cout << endl;
    printbylevel(Pnode);
    return 0;
}
