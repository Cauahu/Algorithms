/*
��Ŀ����
    ��һЩ����������ֻ��3��5��7�������һ���㷨���ҳ����еĵ�k����������һ����int k���뷵�ص�k��������֤kС�ڵ���100��
*/

/*
     * ʱ�临�Ӷ�O(N),������������3����������3��5��7��Ϊ��������
q3,q5,q7������������3��5��7
     * ֮��ÿ������ҵ���������ͷ����С���������Ϊ3����3�Ƴ�����
q3����q3���3*3����q5���3*5,q7�����3*7
     * ��ʱ��֪q3{3*3},q5{5,3*5},q7{7,3*7}
     * ��һ���ҵ���С��Ϊ5���ظ��������裬��5��q5�Ƴ������5*5��
q5����Ϊ5*3�Ѿ���ӹ����Բ���Ҫ��ӵ�q3��
     * ��5*7��ӵ�q7�����q3{3*3},q5{3*5,5*5},q7{7,3*7,5*7}
     * �����ҵ���k����
     */

#include <iostream>
#include <set>


using namespace std;


int findKth(int k) {
    // write code here
    int *ugly=new int[k+1];
    ugly[0]=1;
    int index3=0,index5=0,index7=0;
    int i=1;
    while(i<=k){
    int num3=ugly[index3]*3;
    int num5=ugly[index5]*5;
    int num7=ugly[index7]*7;
    int min=num3;
    if(num5<=min) min=num5;
    if(num7<=min) min=num7;

    if(min==num3) index3++;
    if(min==num5) index5++;
    if(min==num7) index7++;
    ugly[i++]=min;
    }

    int result=ugly[k];
    delete []ugly;
    return result;
}

int main()
{
    set<int> SET;
    SET.insert(3);
    SET.insert(5);
    SET.insert(7);
    //int thread = 3;
    int k, res = 0;
    cin >> k;
    cout << findKth(k) << endl;
    set<int>::iterator iter = SET.begin();
    for(int i=0;i<k;++i)
    {
        res = *iter++;
        SET.insert(res*3);
        SET.insert(res*5);
        SET.insert(res*7);


        /*(switch (thread)
        {
        case 3:
            Q.push(res*3);
            Q.push(res*5);
            Q.push(res*7);
        break;
        case 5:
            Q.push(res*5);
            Q.push(res*7);
            break;
        case 7:
            Q.push(res*7);
            break;
        }
        if(thread == 7)
            thread = 3;
        else
            thread += 2;*/
    }
    cout << res << endl;




    return 0;
}
