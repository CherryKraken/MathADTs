#include <iostream>
#include <vector>
#include <exception>
#include "Matrix.h"

using namespace std;

int main()
{
	try
	{
		Matrix a;
		cout << "----------\n";
		cout << "----------\n";
		cout << endl << a << endl;
		//cout << endl << a * b;
	}
	catch(exception e)
	{
		cout << "***** " << e.what() << endl;
	}

	system("PAUSE");
	return 0;
}