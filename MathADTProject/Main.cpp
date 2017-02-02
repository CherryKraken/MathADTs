#include <iostream>
#include <vector>
#include <exception>
#include "Matrix.h"

using namespace std;

int main()
{
	try
	{
		Matrix a, b;
		a.initialize();
		cout << "----------\n";
		//b.initialize();
		cout << endl << a;
		cout << endl << a * 2;
	}
	catch(exception e)
	{
		cout << "***** " << e.what() << endl;
	}

	system("PAUSE");
	return 0;
}