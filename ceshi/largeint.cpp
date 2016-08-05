class LargeInt
{
public:
	LargeInt(unsigned value = 0, bool sign = true);
	LargeInt(const char *value = "",  bool sign = true);
	~LargeInt();

public:
	LargeInt(const LargeInt &biginteger);

public:
	inline int	len() const { return _len; }
    LargeInt operator+(const LargeInt &biginteger);
	LargeInt operator-(const LargeInt &biginteger);
private:
	LargeInt addwithoutsign(const LargeInt &leftbiginteger,
								const LargeInt &rightbiginteger);
	LargeInt subwithoutsign(const LargeInt &leftbiginteger,
								const LargeInt &rightbiginteger);
private:
	enum { macro_max_len = 1024 };

private:
	char	_value[macro_max_len];
	int     len;
	bool	_positive;
};

LargeInt::LargeInt(unsigned value, bool sign)
{
	_len = 0;
	int i = 0;
	while(value != 0)
	{
		_value[i++] = (value % 10) + '0';
		value /= 10;
	}
	_len = i;
	_positive = sign;
}
LargeInt::LargeInt(const char *value, bool sign)	// "123" means the int 123
{
	_len = 0;
	if(value != null)
	{
		for(int i = 0; i < strlen(value); ++i)
			_value[i] = value[strlen(value) - i - 1];
		_len = strlen(value);
	}
	_positive = sign;
}
LargeInt::~LargeInt()
{

}
LargeInt::LargeInt(const LargeInt &biginteger)
{
	if(&biginteger == this)
		return;

	strcpy(_value, biginteger._value);
	_len = biginteger._len;
	_positive = biginteger._positive;
}
LargeInt LargeInt::operator+(const LargeInt &biginteger)
{
	if(_positive && biginteger._positive)	// + +	--> +
		return addwithoutsign(*this, biginteger);
	if(_positive && !biginteger._positive)	// + -	--> -
		return subwithoutsign(*this, biginteger);
	if(!_positive && biginteger._positive)	// - +	--> -
		return subwithoutsign(biginteger, *this);
	if(!_positive && !biginteger._positive)	// - -	--> +
		return -(addwithoutsign(*this, biginteger));
}
LargeInt LargeInt::operator-(const LargeInt &biginteger)
{
	if(_positive && biginteger._positive)
		return subwithoutsign(*this, biginteger);
	if(_positive && !biginteger._positive)
		return addwithoutsign(*this, -const_cast<LargeInt &>(biginteger));
	if(!_positive && biginteger._positive)
		return -addwithoutsign(*this, biginteger);
	if(!_positive && !biginteger._positive)
		return subwithoutsign(biginteger, *this);
}

LargeInt LargeInt::addwithoutsign(const LargeInt &leftbiginteger,
										  const LargeInt &rightbiginteger)
{
	LargeInt ret((unsigned)0, true);
	int minlen = min(leftbiginteger._len, rightbiginteger.len());
	int promotevalue = 0;
	for(int i = 0; i < minlen; ++i)
	{
		int temp = leftbiginteger._value[i] - '0' + rightbiginteger.intvalueat(i) + promotevalue;
		int temp1 = temp / 10;
		promotevalue = temp1;
		ret.setintat(i, temp - temp1 * 10);
	}
	if(leftbiginteger._len > minlen)
	{
		for(int i = minlen; i < _len; ++i)
		{
			int temp = leftbiginteger._value[i] - '0' + promotevalue;
			int temp1 = temp / 10;
			promotevalue = temp1;
			ret.setintat(i, temp - temp1 * 10);
		}
	}
	if(rightbiginteger.len() > minlen)
	{
		for(int i = minlen; i < rightbiginteger.len(); ++i)
		{
			int temp = rightbiginteger.intvalueat(i) + promotevalue;
			int temp1 = temp / 10;
			promotevalue = temp1;
			ret.setintat(i, temp - temp1 * 10);
		}
	}

	int maxlen = max(_len, rightbiginteger.len());
	ret.setlen(maxlen);
	if(promotevalue > 0)
	{
		ret.setlen(maxlen + 1);
		ret.setcharat(maxlen, promotevalue + '0');
	}
	return ret;
}
LargeInt LargeInt::subwithoutsign(const LargeInt &leftbiginteger,
										  const LargeInt &rightbiginteger)
{
	LargeInt tempminuend(true);
	LargeInt ret(true);
	bool sign = true;
	if(const_cast<LargeInt &>(leftbiginteger).abslessorequal(rightbiginteger))
	{
		tempminuend = rightbiginteger;
		sign = false;

		for(int i = 0; i < leftbiginteger._len; ++i)
		{
			int temp = tempminuend.updatehighposvalue(tempminuend, leftbiginteger, i);
			ret.setintat(i, temp);
		}
		for(int i = leftbiginteger._len; i < tempminuend._len; ++i)
		{
			ret.setintat(i, tempminuend._value[i] - '0');
		}
		if(ret._value[tempminuend._len - 1] == '0')
			ret.setlen(tempminuend._len - 1);
		else
			ret.setlen(tempminuend._len);
	}
	else
	{
		tempminuend = leftbiginteger;
		for(int i = 0; i < rightbiginteger._len; ++i)
		{
			int temp = tempminuend.updatehighposvalue(tempminuend, rightbiginteger, i);
			ret.setintat(i, temp);
		}
		for(int i = rightbiginteger._len; i < tempminuend._len; ++i)
		{
			ret.setintat(i, tempminuend._value[i] - '0');
		}
		if(ret._value[tempminuend._len - 1] == '0')
			ret.setlen(tempminuend._len - 1);
		else
			ret.setlen(tempminuend._len);
	}
	return (sign ? ret : -ret);
}
