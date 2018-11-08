#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class LongInt
{
private:
	int i = 0;
	vector <int> N;
	static const long base = 10 ^ 9;
	static const int length = 9;
	bool signMinusOfInt = 0;

	void stringToInt(const string& a);
	void resizeN(LongInt& other, LongInt res);
	void removeZeroHead();
	void normalize();
	int elemOfN(int elem);

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
	friend ostream& operator << (ostream& stream, LongInt& longInt);
	friend istream& operator >> (ostream& stream, LongInt& longInt);

	bool simplicityLeman();


};

