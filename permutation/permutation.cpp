#include <iostream>
#include <string>

using namespace std;

void permutation(string str, int pos, int len)
{
	if(pos == len)
		cout << str << endl;
	else
	{
		for(int i=pos;i<=len;++i)
		{
			swap(str[pos], str[i]);
			cout << "交换：" << pos << " " << i << endl;
			permutation(str, pos+1, len);
			swap(str[pos], str[i]);
			cout << "交换：" << pos << " " << i << endl;

		}
	}

}


int main()
{
	
	permutation("abc",0,2);
	return 0;

}
