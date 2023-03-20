#include <iostream>
#include <fstream>
using namespace std;

/*
* Andrew Humphreys Pgm5 CS2010 LEC1003
* 
* 
* 
*
*/

const char INPUT_FILE[] = "pgm5-1.txt";

int main()
{
	// First todo:
	// read "pgm5.txt";
	ifstream realtorSalesData;

	realtorSalesData.open(INPUT_FILE);

	if (!realtorSalesData.is_open())
	{
		cout << "Error reading " << INPUT_FILE << "." << endl;
		return 0;
	}

}