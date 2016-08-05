#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
void getresult(int orignal)
{
    if(orignal == 6174)
        return;

    vector<int> num;
    int large = 0, little = 0, base = 1000;
    for(int i=0;i<4;++i)
    {
        num.push_back(orignal % 10);
        orignal /= 10;
    }

    sort(num.begin(), num.end(), greater<int>());
    for(int i=0;i<4;++i)
    {
        large += num[i]*base;
        base /= 10;
    }
    base = 1000;

    sort(num.begin(), num.end());
    for(int i=0;i<4;++i)
    {
            little += num[i]*base;
            base /= 10;
    }
    printf("%04d - %04d = %04d\n",large, little, large-little);
    getresult(large-little);
}*/


class ccbiginteger
{
public:
	ccbiginteger(unsigned value = 0, bool sign = true);
	ccbiginteger(const char *value = "",  bool sign = true);
	~ccbiginteger();

public:
	ccbiginteger(const ccbiginteger &biginteger);
	ccbiginteger &operator=(const ccbiginteger &biginteger);

public:
	inline int	len() const { return _len; }
	inline char charvalueat(int index) const { return  _value[index]; }
	inline int	intvalueat(int index) const { return _value[index] - '0'; }

public:
	inline void	setlen(int newlen) { _len = newlen; }
	inline void setcharat(int index, char newchar) { _value[index] = newchar; }
	inline void setintat(int index, int newint) { _value[index] = newint + '0'; }

public:
	bool		cangetintvalue() const;	// if the unsigned value is overflowed, then returns false
	unsigned	uintvalue() const;
	char	    *str() const;		// the char * format value, 239094843343 returns "239094843343"; caller should free the return value

public:
	ccbiginteger operator+(const ccbiginteger &biginteger);
	ccbiginteger operator-(const ccbiginteger &biginteger);

public:
	ccbiginteger  operator-();		// neg
public:
	friend bool	operator<=(const ccbiginteger &leftbiginteger,
						  const ccbiginteger &rightbiginteger);
	bool		abslessorequal(const ccbiginteger &biginteger);

private:
	ccbiginteger addwithoutsign(const ccbiginteger &leftbiginteger,
								const ccbiginteger &rightbiginteger);
	ccbiginteger subwithoutsign(const ccbiginteger &leftbiginteger,
								const ccbiginteger &rightbiginteger);

private:
	// when subing, the function is called to update the high position value of the minuend
	int			updatehighposvalue(ccbiginteger &minuend,
												 const ccbiginteger &subtrahend,
												 int pos);

private:
	enum { macro_max_len = 1024 };

private:
	char	_value[macro_max_len];	// "321" means the integer 123, not 321
	int		_len;				// the length of the value, should be less to macro_max_len
	bool	_positive;			// is positive or not
};

class LargeInt{
public:
    LargeInt()
    {
        sign = true;
    }

    LargeInt(string s_num)
    {
        int len = s_num.size()-1;
        for(int i= len;i>-1;--i)
            num.push_back(s_num[i]-'0');
    }

    LargeInt(const LargeInt& li);
    ~LargeInt()
    {
        num.clear();
    }

public :
    int length();
    LargeInt operator+ (const LargeInt &li) const;
    LargeInt operator- (const LargeInt &li) const;


private:
    LargeInt addwithoutsign(const LargeInt &leftlargeint, const LargeInt &rightlargeint);
	LargeInt subwithoutsign(const LargeInt &leftlargeint, const LargeInt &rightlargeint);

private:
    vector<char> num;
    bool sign;
};
LargeInt::LargeInt(const LargeInt& li)
{
    copy(li.num.begin(), li.num.end(), num.begin());
}
int LargeInt::length()
{
    return num.size();
}

LargeInt LargeInt::addwithoutsign(const LargeInt& leftlargein, const LargeInt &rightlargeint)
{
    int leftlen = leftlargein.length(), rightlen = rightlargeint.length();
    int i = 0, endflag = min(leftlen, rightlen);
    LargeInt result;
    for(;i<endflag;++i)
    {
        result
    }
}

LargeInt LargeInt::operator+(const LargeInt &li) const
{

}

/*
int main()
{
    getresult(6767);

    return 0;
}
*/
