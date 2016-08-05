#include <iostream>
#include "BigInter.h"
using namespace std;

int main()
{
    BigIntger bgint1("1357");
    BigIntger bgint2("9876");

    BigIntger result = bgint1 + bgint2;
    cout << result.getValue() << endl;
    result = bgint1 - bgint2;
    cout << result.getValue() << endl;
    return 0;
}
