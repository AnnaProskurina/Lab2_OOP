#include "stdafx.h"
#include "LongInt.h"
#include <string>

using namespace std;

LongInt::LongInt()
{
	N.push_back(0);
}

LongInt::~LongInt()
{
	N.clear();
}

void LongInt::stringToInt(const string & a)
{
	string temp = a;
	int localBase = 10;
	int r = 0, p =0;

	if (temp.begin == '-')
	{
		signMinusOfInt = 1;
		temp.erase(temp.begin);
	}
	else signMinusOfInt = 0;

		if (temp.size() > 2)
		{
			p = atoi(temp.substr(0, 2).c_str());
			int i = 1;

			while( i < temp.size())
			{
				if (p < localBase)
				{
					p = p*10 + atoi(temp.substr(i, 1).c_str());
					i++;
				}
				while (p >= localBase)
				{
					r = p%base;
					p = p / base;
					N.push_back(r);
				}
			}

		}

		else 
			for (int i = temp.size(); i > 0; i--)
			{
				N.push_back(atoi(temp.substr(i-1, 1).c_str()));
			}
}

void LongInt::resizeN(LongInt & other, LongInt res)
{
	if (N.size() > other.N.size)  res.N.resize(N.size());
	else 
		res.N.resize(other.N.size());
}

void LongInt::removeZeroHead()
{
	if (N.size() > 1 && N.back() == 0) N.pop_back();
}

void LongInt::normalize()
{
	for (int i = 0; i < N.size() - 1; i++)
	{
		if (N[i] < 0)
		{
			N[i] = N[i] + base;
			N[i + 1] --;
		}

	}
}

int LongInt::elemOfN(int elem)
{
	if (elem < 0 || elem > N.size()) return 0;
	return N[elem];
}


bool LongInt::operator>(LongInt & other)
{
	if (signMinusOfInt == 1 && other.signMinusOfInt == 0) return false;
	if (signMinusOfInt == 0 && other.signMinusOfInt == 1) return true;

	if (signMinusOfInt == 0 && other.signMinusOfInt == 0)
	{
		if (N.size() != other.N.size()) return N.size() > other.N.size();
		for (int i = N.size(); i >= 0; i--)
		{
			if (elemOfN(i) != other.elemOfN(i)) return elemOfN(i) > other.elemOfN(i);
		}
	}

	else
		if (signMinusOfInt == 1 && other.signMinusOfInt == 1)
		{
			if (N.size() != other.N.size()) return N.size() < other.N.size();
			for (int i = N.size(); i >= 0; i--)
			{
				if (elemOfN(i) != other.elemOfN(i)) return elemOfN(i) < other.elemOfN(i);
			}
		}
}

bool LongInt::operator>=(LongInt & other)
{
	return *this > other || *this == other;
}

bool LongInt::operator<(LongInt & other)
{
	if (signMinusOfInt == 1 && other.signMinusOfInt == 0) return true;
	if (signMinusOfInt == 0 && other.signMinusOfInt == 1) return false;

	if (signMinusOfInt == 0 && other.signMinusOfInt == 0)
	{
		if (N.size() != other.N.size()) return N.size() < other.N.size();
		for (int i = N.size(); i >= 0; i--)
		{
			if (elemOfN(i) != other.elemOfN(i)) return elemOfN(i) < other.elemOfN(i);
		}
	}

	else
		if (signMinusOfInt == 1 && other.signMinusOfInt == 1)
		{
			if (N.size() != other.N.size()) return N.size() > other.N.size();
			for (int i = N.size(); i >= 0; i--)
			{
				if (elemOfN(i) != other.elemOfN(i)) return elemOfN(i) > other.elemOfN(i);
			}
		}
}

bool LongInt::operator<=(LongInt & other)
{
	return *this < other || *this == other;
}

bool LongInt::operator==(LongInt & other)
{
	if (signMinusOfInt != other.signMinusOfInt) return false;
	if (N.size() != other.N.size()) return false;

	for (int i = 0; i < N.size(); i++)
	{
		if (N[i] != other.N[i]) return false;
	}

	return true;
}

bool LongInt::operator!=(LongInt & other)
{
	return !(*this == other);
}

LongInt LongInt::operator-(LongInt & other)
{
	LongInt res;
	if (other.N.empty()) { res = *this;  return res; }
	if (this->N.empty() && (other.signMinusOfInt = 0)) { res = other;  res.signMinusOfInt = 1; return res; }
	if (this->N.empty() && (other.signMinusOfInt = 1)) { res = other;  res.signMinusOfInt = 0; return res; }

	if (other.signMinusOfInt)
	{
		other.signMinusOfInt = 0;
		res = *this + other;
		return res;
	}

	if (*this == other) { res.N.push_back(0); return res; }

	resizeN(other, res);
	if (*this > other)
	{
		res.signMinusOfInt = 0;
		for (int i = 0; i < N.size(); i++)
		{
			res.N[i] = N[i] - other.N[i];
		}
	}

	if (*this < other)
	{
		res.signMinusOfInt = 1;
		for (int i = 0; i < N.size(); i++)
		{
			res.N[i] = other.N[i] - N[i];
		}
	}
	removeZeroHead();
	normalize();
	return res;
}

LongInt LongInt::operator+(LongInt & other)
{
	LongInt res;
	if (other.signMinusOfInt)
	{
		other.signMinusOfInt = false;
		res = *this - other;
		return res;
	}
	resizeN(other, res);
	for (int i = 0; i < N.size(); i++)
	{
		res.N[i] = N[i] + other.N[i];
	}
	//toBase
	return res;
}

LongInt LongInt::operator*(LongInt & other)
{
	LongInt res;
	//res = currentM->multiply(*this, other);
	return res;
}

