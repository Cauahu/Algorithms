#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
/*
���һ���㷨����һ������N��Ԫ�ص�����ѭ������Kλ��Ҫ��ʱ�临�Ӷ�ΪO(N)����ֻ����ʹ���������ӱ�����
K�п��ܴ���N��������Kλ�����Σ�������K1=K%N������һ����
����ԭ��������Ϊabcd1234��Ҫ��任���Ϊ1234abcd����ѭ��������4λ������ͨ������������ɲ�����
1.��������abcd��abcd1234 -> dcba1234
2.��������1234: dcba1234 -> dcba4321
3.��������ȫ����dcba4321 -> 1234abcd
*/
    char a[] = "abcd1234";
    int i=0;
    while(a[i++]!='\0');
    int N;
    cin >> N;
    while(N!=0)
    {
        N %= i;
        reverse(a,a+i-N-1);
        cout << a << endl ;
        reverse(a+i-N-1,a+i-1);
        cout << a << endl ;
        reverse(a,a+i-1);
        cout << a << endl << endl << endl ;
    }
    return 0;
}
