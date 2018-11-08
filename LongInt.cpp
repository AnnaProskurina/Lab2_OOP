#include "stdafx.h"
#include "LongInt.h"
#include <vector>
#include <string>
#include <cstring>


using namespace std;

LongInt::LongInt()
{
	LongInt t = *this;
	t.N.push_back(0);
}

LongInt::~LongInt()
{
	LongInt t = *this;
	t.N.clear();
}

LongInt::LongInt(const string & a)
{
	stringToInt(a);
}



void LongInt::stringToInt(const string & a)
{
	LongInt t = *this;
	string temp = a;
	if (temp[0] == '-')
	{
		signMinusOfInt = 1;
		temp.erase(temp.begin());
	}
	else t.signMinusOfInt = 0;


	for (long i = temp.size()-1; i >= 0; i--)
	{
			t.N.push_back(temp[i]);
	}
}


void LongInt::resizeN(LongInt & other, LongInt res)
{
	LongInt t = *this;
	if (t.N.size() > other.N.size())  res.N.resize(N.size());
	else 
		res.N.resize(other.N.size());
}

void LongInt::removeZeroHead()
{
	LongInt t = *this;
	if (t.N.size() > 1 && t.N.back() == 0) t.N.pop_back();
}

void LongInt::normalize()
{
	LongInt t = *this;
	for (long i = 0; i <t.N.size() - 1; i++)
	{
		if (t.N[i] < 0)
		{
			t.N[i] = t.N[i] + base;
			t.N[i + 1] --;
		}

	}
}

int LongInt::elemOfN(int elem)
{
	LongInt t = *this;
	if (elem < 0 || elem > t.N.size()) return 0;
	return t.N[elem];
}


bool LongInt::operator>(LongInt & other)
{
	LongInt t = *this;
	if (t.signMinusOfInt == 1 && other.signMinusOfInt == 0) return false;
	if (t.signMinusOfInt == 0 && other.signMinusOfInt == 1) return true;

	if (t.signMinusOfInt == 0 && other.signMinusOfInt == 0)
	{
		if (t.N.size() != other.N.size()) return N.size() > other.N.size();
		for (long i = t.N.size(); i >= 0; i--)
		{
			if (t.elemOfN(i) != other.elemOfN(i)) return (t.elemOfN(i) > other.elemOfN(i));
		}
	}

	else
		if (t.signMinusOfInt == 1 && other.signMinusOfInt == 1)
		{
			if (t.N.size() != other.N.size()) return t.N.size() < other.N.size();
			for (long i = t.N.size(); i >= 0; i--)
			{
				if (t.elemOfN(i) != other.elemOfN(i)) return t.elemOfN(i) < other.elemOfN(i);
			}
		}
}

bool LongInt::operator>=(LongInt & other)
{
	return *this > other || *this == other;
}

bool LongInt::operator<(LongInt & other)
{
	LongInt t = *this;
	if (t.signMinusOfInt == 1 && other.signMinusOfInt == 0) return true;
	if (t.signMinusOfInt == 0 && other.signMinusOfInt == 1) return false;

	if (t.signMinusOfInt == 0 && other.signMinusOfInt == 0)
	{
		if (t.N.size() != other.N.size()) return t.N.size() < other.N.size();
		for (long i = t.N.size(); i >= 0; i--)
		{
			if (t.elemOfN(i) != other.elemOfN(i)) return t.elemOfN(i) < other.elemOfN(i);
		}
	}

	else
		if (t.signMinusOfInt == 1 && other.signMinusOfInt == 1)
		{
			if (t.N.size() != other.N.size()) return t.N.size() > other.N.size();
			for (long i = t.N.size(); i >= 0; i--)
			{
				if (t.elemOfN(i) != other.elemOfN(i)) return t.elemOfN(i) > other.elemOfN(i);
			}
		}
}

bool LongInt::operator<=(LongInt & other)
{
	return *this < other || *this == other;
}

bool LongInt::operator==(LongInt & other)
{
	LongInt t = *this;
	if (t.signMinusOfInt != other.signMinusOfInt) return false;
	if (t.N.size() != other.N.size()) return false;

	for (long i = 0; i < N.size(); i++)
	{
		if (t.N[i] != other.N[i]) return false;
	}

	return true;
}

bool LongInt::operator!=(LongInt & other)
{
	return !(*this == other);
}

LongInt LongInt::operator-(LongInt & other)
{
	LongInt t = *this;
	LongInt res;
	if (other.N.empty()) { res = t;  return res; }
	if (this->N.empty() && (other.signMinusOfInt = 0)) { res = other;  res.signMinusOfInt = 1; return res; }
	if (this->N.empty() && (other.signMinusOfInt = 1)) { res = other;  res.signMinusOfInt = 0; return res; }

	if (other.signMinusOfInt)
	{
		other.signMinusOfInt = 0;
		res = t + other;
		return res;
	}

	if (t == other) { res.N.push_back(0); return res; }

	resizeN(other, res);
	if (t > other)
	{
		res.signMinusOfInt = 0;
		for (long i = 0; i < t.N.size(); i++)
		{
			res.N[i] = t.N[i] - other.N[i];
		}
	}

	if (*this < other)
	{
		res.signMinusOfInt = 1;
		for (int i = 0; i < t.N.size(); i++)
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
	LongInt t = *this;
	LongInt res;
	if (other.signMinusOfInt)
	{
		other.signMinusOfInt = false;
		res = t - other;
		return res;
	}
	resizeN(other, res);
	for (long i = 0; i <t.N.size(); i++)
	{
		res.N[i] = t.N[i] + other.N[i];
	}
	return res;
}

LongInt LongInt::operator*(LongInt & other)
{
	LongInt res, t = *this;
	if ((t.signMinusOfInt == 0 && other.signMinusOfInt) || (t.signMinusOfInt && other.signMinusOfInt == 0))
	{
		res.signMinusOfInt = 1;
	}
	if (t.N[t.N.size() - 1] == 0 || other.N[other.N.size() - 1] == 0) { return res; }
	res.resizeN(other, res);
	res.N.resize(res.N.size()*2);

	for (long i = 0; i < t.N.size(); i++) {
		for (long j = 0; j < other.N.size(); j++)
			res.N[i + j] = t.N[i] * other.N[j];
	}
	res.normalize();
	return res;
}


/*
LongInt LongInt::operator/(LongInt & other)
{
	LongInt res, rem, t = *this;
	if (t == other) 
	{ 
		res.N.push_back(1);
		return res;
	}

	if (t.N[t.N.size()-1] == 0) { return res; }
	if (other.N[other.N.size() - 1] == 0) { throw exception("Division by zero"); }

	if ((t.signMinusOfInt == 0 && other.signMinusOfInt) || (t.signMinusOfInt && other.signMinusOfInt == 0))
	{
		res.signMinusOfInt = 1;
	}

	res.resizeN(other, res);

}
*/

ostream & operator<<(ostream & stream, LongInt & longInt)
{
	for (long i = longInt.N.size() - 1; i >= 0; i--)
		stream << longInt.N[i];
	return stream;
}

istream & operator>>(istream & stream, LongInt & longInt)
{
	longInt.N.clear();
	string str;
	stream >> str;
	longInt.stringToInt(str);
	return stream;
}

/*bool LongInt::simplicityLeman()
{

}*/