#pragma once
#include "Multer.h"
#include <iostream>

using namespace std;

class LongInt
{
private:
	Multer* m;
	int n[1000];
	string a, b;

public:
	LongInt();
	const LongInt operator* ()
	{
		//m->multiply(A, B);
	}
	//reload + - >> <<

	LongInt getIntegers();
};

