#include <iostream>
#include <queue>

using namespace std;


void shellsort(int *a, int n)
{
	int d=n/2;
	while(d > 0)
	{
		for(int i=d;i<n;i++)
		{
			if(a[i-d] > a[i])
				swap(a[i-d], a[i]);
		}
		d /= 2;
	}

}

void quiksort(int *a, int b, int e)
{
	int i = b , j = e, temp ;
	if(i<j)
	{
		while(i<j)
		{
			temp = a[i];
			while(i<j&& temp < a[j])
				j--;
			if(i<j)
				a[i++] = a[j];
			while(i<j&& temp > a[i])
				i++;
			if(i<j)
				a[j--] = a[i];
		}
		a[i] = temp;
		quiksort(a,b,i-1);
		quiksort(a,i+1,e);
	}
}


void bubblingsort(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);
		}
	}
}


void selectsort(int *a, int n)
{
    /*
    每一趟从待排序的数据元素中选出最小（或最大）的一个元素，顺序放在已排好序的数列的最后，
    直到全部待排序的数据元素排完。 选择排序是不稳定的排序方法。算法复杂度是O(n ^2 )。
    */

    for(int i=0;i<n-1;i++)
    {
        int m = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[m] > a[j])
                m = j;
        }
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }

}

void insertsort(int *a ,int n)
{
    /*
    每次从无序表中取出第一个元素，把它插入到有序表的合适位置，使有序表仍然有序。
    直接插入排序是稳定的。算法时间复杂度是O(n ^2)
    */
    for(int i=1;i<n;i++)
    {
        int temp = a[i];
        int j=i;
        for(;temp<a[j-1];j--)
            a[j] = a[j-1];
        a[j] = temp;
    }
}

void radixsort(int *a, int n)
{
    /*

    */
    vector<queue<int> > RAD(10);
    bool flag = false;
    int carry = 10;
    int r = 2;
    while(r--)
    {
        flag = true;
        for(int i=0;i<n;i++)
        {
            //if((a[i]/carry)!=0)
             //   flag = false;
             int cur = a[i]%carry/(carry/10);
            RAD[cur].push(a[i]);
        }
        for(int i=0,j=0;i<10;i++)
        {
            while(!RAD[i].empty())
            {
                 a[j++] = RAD[i].front();
                 RAD[i].pop();
            }
        }
        carry *= 10;
    }
}

int main()
{
    //int a[] = {6,2,7,4,1,8,3,5};
    //selectsort(a,8);
    int a[] = {73, 22, 93, 43, 55, 14, 28, 65};
    //radixsort(a,8);
	//bubblingsort(a,8);
	//shellsort(a,8);
	quiksort(a,0,7);
    for(int i=0;i<8;i++)
        cout << a[i] << " ";
	cout << endl;
    return 0;
}
