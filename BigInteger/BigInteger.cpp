#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
#include "BigInter.h"

using namespace std;

BigIntger::BigIntger(unsigned value, bool sign)
{
    _len = 0;
    int i = 0;
    while(value != 0)
    {
        _value[i++] = (value % 10);
        value /= 10;
    }
    _len = i;
    _positive = sign;
}

BigIntger::BigIntger(const char * value, bool sign)
{
    _len = 0;
    int len = strlen(value);
    for(int i=0;i<len;++i)
        _value[i] = value[len-i-1] - '0';
    _len = strlen(value);
    _positive = sign;
}

BigIntger::BigIntger(const BigIntger &bigintger)
{
    if(&bigintger == this)
        return;
    strcpy(_value, bigintger._value);
    _len = bigintger._len;
    _positive = bigintger._positive;
}

BigIntger& BigIntger::operator=(const BigIntger &bigintger)
{
    if(&bigintger == this)
        return *this;

    int len = bigintger._len;
    for(int i=0; i<len;++i)
        _value[i] = bigintger._value[i];
    this->_len = bigintger._len;
    this->_positive = bigintger._positive;

    return *this;
}

BigIntger::~BigIntger()
{

}

BigIntger BigIntger::addwithoutsign(const BigIntger &leftbigint, const BigIntger &rightbigint)
{
    BigIntger result((unsigned)0,true);
    int minlen = min(leftbigint._len, rightbigint._len);
    for(int i=0; i < minlen; ++i)
            result._value[i] = leftbigint._value[i] + rightbigint._value[i];
    if(leftbigint._len > minlen)
    {
        int len = leftbigint._len;
        for(int i=minlen;i<len;++i)
            result._value[i] = leftbigint._value[i];
    }
    if(rightbigint._len > minlen)
    {
        int len = rightbigint._len;
        for(int i=minlen;i<len;++i)
            result._value[i] = rightbigint._value[i];
    }
    result._len = max(leftbigint._len, rightbigint._len);
    int len = result._len, carry = 0;
    for(int i=0;i<len;++i)
    {
        int temp = result._value[i] + carry;
        result._value[i] = temp % 10;
        carry = temp / 10 ;
    }
    if(carry != 0)
        result._value[result._len++] = carry;
    return result;
}

BigIntger BigIntger::subwithoutsign(const BigIntger &leftbigint, const BigIntger &rightbigint)
{
    BigIntger result((unsigned)0, true);
    const char* sub1 = leftbigint._value, *sub2 = rightbigint._value;
    if(rightbigint._len > leftbigint._len)
    {
        sub1 = rightbigint._value;
        sub2 = leftbigint._value;
        result._positive = false;
    }
    else if(rightbigint._len == leftbigint._len)
    {
        int len = leftbigint._len - 1;
        for(int i=len;i>-1;--i)
        {
            if(sub1[i] < sub2[i])
            {
                sub1 = rightbigint._value;
                sub2 = leftbigint._value;
                result._positive = false;
                break;
            }
        }
    }

    int len = min(leftbigint._len, rightbigint._len);
    for(int i=0;i<len;++i)
        result._value[i] = sub1[i] - sub2[i];
    if(leftbigint._len > len)
    {
        for(int i=len;i<leftbigint._len;++i)
            result._value[i] = leftbigint._value[i];
    }

    if(rightbigint._len > len)
    {
        for(int i=len;i<rightbigint._len;++i)
            result._value[i] = rightbigint._value[i];
    }

    len = max(leftbigint._len, rightbigint._len);
    int borrow = 0;
    for(int i=0;i<len;++i)
    {
        if(result._value[i] < 0 || (result._value[i] < 0 && borrow == -1))
        {
            result._value[i] = 10 + result._value[i] + borrow;
            borrow = -1;
        }
        else
        {
            result._value[i] = result._value[i] + borrow;
            borrow = 0;
        }
    }
    result._len = len;
    if(borrow == -1)
        result._value[result._len++] = 9;
    return result;
}

BigIntger BigIntger::operator+ (const BigIntger &biginteger)
{
    BigIntger result((unsigned)0,true);
    if(_positive && biginteger._positive) // + + --> +
        result = addwithoutsign(*this, biginteger);
    else if(_positive && !biginteger._positive) // + - --> + -
        result = subwithoutsign(*this, biginteger);
    else if(!_positive && biginteger._positive)
        result = subwithoutsign(biginteger, *this);
    else if(!_positive && !biginteger._positive)
    {
        result = addwithoutsign(*this, biginteger);
        result._positive = false;
    }
    return result;


}

BigIntger BigIntger::operator- (const BigIntger &biginteger)
{
    BigIntger result((unsigned)0,true);
    if(_positive && biginteger._positive) // + +
        result = subwithoutsign(*this, biginteger);
    else if(_positive && !biginteger._positive) // + -
        result = addwithoutsign(*this, biginteger);
    else if(!_positive && biginteger._positive)
    {
        result = addwithoutsign(biginteger, *this);// - +
        result._positive = false;
    }
    else if(!_positive && !biginteger._positive) // - -
        result = addwithoutsign(*this, biginteger);
    return result;
}

const char* BigIntger::getValue()
{
    int i, len = this->_len + 1;;
    char *res;
    if(!_positive)
    {
        res = new char[len + 1];
        res[0] = '-';
        i = 1;
    }
    else{
        res = new char[len];
        i = 0;
    }
    for(;i<len;++i)
        res[i] = _value[len-i-1] + '0';
    res[len] = '\0';
    return res ;
}








