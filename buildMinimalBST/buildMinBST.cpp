#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int len = 0;
	while(cin >> len){
		double result = log(len) / log(2);
		cout << ceil(result) << endl;
	}
	return 0;
}
