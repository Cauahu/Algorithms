//a kind of decimal big integer

class BigIntger
{
public:
    BigIntger(unsigned value = 0, bool sign = true);
    BigIntger(const char *value = "", bool sign = true);
    BigIntger(const BigIntger &biginteger);
    BigIntger& operator= (const BigIntger& bigintger);
    ~BigIntger();

public:
    BigIntger operator+ (const BigIntger &biginteger);//�����ŵ�+
    BigIntger operator- (const BigIntger &biginteger);//�����ŵ�-

    BigIntger addwithoutsign(const BigIntger &leftbigint, const BigIntger &rightbigint);//�������ŵ�+
    BigIntger subwithoutsign(const BigIntger &leftbigint, const BigIntger &rightbigint);//�������ŵ�-
    const char* getValue();

private:
    enum {MAX_LEN = 1024};
    char _value[MAX_LEN];
    int _len;
    bool _positive;
};
