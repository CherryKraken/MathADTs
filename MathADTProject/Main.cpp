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
		a.initialize(3, 3);
		b.initialize(2, 3);
		cout << a+b;
	}
	catch(exception e)
	{
		cout << "***** " << e.what() << endl;
	}

	system("PAUSE");
	return 0;
}