#pragma once
#include "LongInt.h"

class Multer
{
private:

public:
	Multer();
	virtual LongInt multiply(LongInt A, LongInt B);
};


class Karatsuba : protected Multer
{
private:

public:
	LongInt multiply(LongInt A, LongInt B);
};
