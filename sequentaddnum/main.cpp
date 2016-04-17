#include <iostream>

using namespace std;

void questionone(int n)
{
    /*
    问题1：写一个程序，对于一个数，输出他所有可能的连续自然数之和的算式。
    解：num = a + a+1 + a+2 + a+3 + ...... + a+k-2 + a+k-1 = k(a+a+k-1)/2
            = ka + k(k-1)/2
        k是整数，a是整数，所以k(k-1)/2也是整数。
    */
    int k,i,temp = 0;
    int flag = 1;//od用来判断k的奇偶性，flag用来判断是否存在a
    for(k=2;n>temp;k++)
    {
        temp = k*(k-1)/2;
        if((n-temp)%k==0)
        {
            flag = 0;
            i = (n-temp)/k;
            int cur = k-1;
            cout << n << " = ";
            while(cur--)
                cout << i++ << "+";
            cout << i << ";" <<endl;
        }
    }
    if(flag)
        cout << n << "不能表示为连续数字和的形式。" << endl;
}

void questiontwo()
{
    /*
    问题2：那些不能表示为连续数字和的形式的数字有什么规律？
    解：
    num =  = ka + k(k-1)/2 = k(2i+k-1)/2,由此可知2i是偶数，若k为奇数，k-1为偶数，令X=(2i+k-1)为偶数，所以num=k*X(奇数*偶数)；
    若k为偶数，则(2i+k-1)为奇数，所以num=(奇数*偶数)。
    综上num必须能写成奇数与偶数的乘积，所以只有2^n不能够写成连续数字和的形式。
    */
}


int main()
{
    questionone(9);
    questionone(8);
    questionone(32);
    return 0;
}
