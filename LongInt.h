#pragma once
#include "Multer.h"
#include <vector>
#include <string>
#include <iostream>


class LongInt
{
private:
	Multer* m;
	int i = 0;
	vector <int> N;

public:
	LongInt (string a);

	const LongInt operator* ()
	{
		//m->multiply(A, B);
	}
	//reload + - >> <<

	const LongInt operator<< (LongInt* A)
	{
	//	cout <<  ;
	}
};

