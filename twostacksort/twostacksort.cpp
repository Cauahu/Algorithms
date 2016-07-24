#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	stack<int> orignal;
	stack<int> aftersort;
	orignal.push(4);
	orignal.push(2);
	orignal.push(3);
	orignal.push(1);
	orignal.push(5);

	aftersort.push(orignal.top());
	orignal.pop();

	while(!orignal.empty())
	{
		int temp = orignal.top();
		orignal.pop();
		while(temp > aftersort.top() && !aftersort.empty())
		{
			orignal.push(aftersort.top());
			aftersort.pop();
		}
		
		aftersort.push(temp);
	}

	while(!aftersort.empty())
	{
		cout << aftersort.top() << " ";
		aftersort.pop();
	}

	cout << endl;
}


