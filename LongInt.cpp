#include "stdafx.h"
#include "LongInt.h"
#include <string>

using namespace std;


LongInt::LongInt(string a)
{
	int A = stoi(a);
	N[i] = A;
	i++;
}

LongInt::LongInt()
{
	N.push_back(0);
}

LongInt LongInt::operator+(LongInt & other)
{
	LongInt res;
	if (other.signMinusOfInt)
	{
		other.signMinusOfInt = false;
		res = this - other;
		return res;
	}
}
