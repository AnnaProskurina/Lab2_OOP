#include "stdafx.h"
#include<iostream>
#include "LongInt.h"
//#include "Multer.h"


using namespace std;



int main()
{
	string a;
	cout << "Enter a long integer" << endl;
	cin >> a;
	LongInt A(a);
	try
	{
		cout << A << endl;

	}
	catch (exception &e)
	{
		cout << "Error" << e.what() << endl;
	}
	system("pause");
    return 0;
}

