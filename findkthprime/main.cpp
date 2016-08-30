/*
题目描述
    有一些数的素因子只有3、5、7，请设计一个算法，找出其中的第k个数。给定一个数int k，请返回第k个数。保证k小于等于100。
*/

/*
     * 时间复杂度O(N),按书中所讲，3个素数因子3、5、7分为三个队列
q3,q5,q7，其中最初存放3，5，7
     * 之后每次添加找到三个队列头中最小的数，起初为3，将3移出队列
q3后，在q3添加3*3，在q5添加3*5,q7中添加3*7
     * 此时可知q3{3*3},q5{5,3*5},q7{7,3*7}
     * 下一轮找到最小数为5，重复上述步骤，将5从q5移出，添加5*5到
q5，因为5*3已经添加过所以不需要添加到q3中
     * 将5*7添加到q7，结果q3{3*3},q5{3*5,5*5},q7{7,3*7,5*7}
     * 依次找到第k个数
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
