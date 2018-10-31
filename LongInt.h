#pragma once
#include "Multer.h"
#include <vector>
#include <string>
#include <iostream>


class LongInt
{
private:
	int i = 0;
	vector <int> N;
	static const long base = 10 ^ 9;
	bool signMinusOfInt;
	void stringToInt(const string& a);

public:
	LongInt();
	LongInt (const string& a);

	LongInt operator* ()
	{
		//m->multiply(A, B);
	}
	//reload + - >> <<

	LongInt operator+ (LongInt& other);
};

