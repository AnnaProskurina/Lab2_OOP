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
	static const int length = 9;
	bool signMinusOfInt = 0;
	static Multer *currentM;

	void stringToInt(const string& a);
	void resizeN(LongInt& other, LongInt res);
	void removeZeroHead();
	void toBase(int base1, int base2);
	void normalize();
	int elemOfN(int elem);

	/*
	@ setter of multiplication type
	*/

public:
	LongInt();
	~LongInt();
	LongInt (const string& a);

	
	bool operator> (LongInt& other);
	bool operator>= (LongInt& other);
	bool operator< (LongInt& other);
	bool operator<= (LongInt& other);
	bool operator== (LongInt& other);
	bool operator!= (LongInt& other);
	LongInt operator- (LongInt& other);
	LongInt operator+ (LongInt& other);
	LongInt operator* (LongInt& other);
};

