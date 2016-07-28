#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string printBin(double num)
{
	vector<int> vec;

	int i = 0;
	while(num != 0.0)
	{
		num *= 2;
		cout << num << endl;
		if(num >= 1)
		{
			vec.push_back(1);
			num -= 1;
		}
		else{
			vec.push_back(0);
		}
		++i;
	}
	vec.push_back(1);

	string res = "0.";
	if(vec.size() > 32)
		return "error";
	while( i > 0)
		res += vec[--i]+'0';
	return res;
}


int main()
{
	double n;
	while( cin >> n){
		cout << printBin(n) << endl;
	}
}

