#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binIsert(int n, int m, int j, int i)
{
	vector<int> vecn;
	vector<int> vecm;

	while(n)
	{
		if((n & 1) == 0)
			vecn.push_back(0);
		else
			vecn.push_back(1);
		n = n>>1;
	}

	while(m)
	{
		if((m & 1) == 0)
			vecm.push_back(0);
		else
			vecm.push_back(1);
		m = m>>1;
	}

	int lenn = vecn.size(), lenm = vecm.size();
	for(int k =0;k<lenn;++k)
		cout << vecn[k];
	cout << endl;
	for(int k =0;k<lenm;++k)
		cout << vecm[k];
	cout << endl;

	int len = (i - j + 1) < vecm.size() ? i - j + 1 : vecm.size() ;
	for(int k=0;k < len;++k)
		vecn[j+k] = vecm[k];
	for(int k =0;k<lenn;++k)
		cout << vecn[k];
	cout << endl;


	len = vecn.size();

	int result = 0, x = 1;
	for(int k=0;k < len;++k)
	{
		if(vecn[k] == 1)
			result += x;
		x *= 2;
	}

	return result;
}

int binIsert_val1(int n, int m, int j, int i)
{
	int t = pow(2, j);
	return n+m*t;
}


int main()
{
	cout <<	binIsert(61482, 3, 6, 11) << endl;
}
