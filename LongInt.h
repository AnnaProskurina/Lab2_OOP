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
	void resizeN(LongInt& other, LongInt res);

	/*
	@ toBase 
	@ removeZeroHead (if last == 0 remove)
	*/

	void normalize();
	int elemOfN(int elem);

public:
	LongInt();
	LongInt (const string& a);

	
	bool operator> (LongInt& other);
	bool operator>= (LongInt& other);
	bool operator< (LongInt& other);
	bool operator<= (LongInt& other);
	bool operator== (LongInt& other);
	bool operator!= (LongInt& other);
	LongInt operator- (LongInt& other);
	LongInt operator+ (LongInt& other);
};

