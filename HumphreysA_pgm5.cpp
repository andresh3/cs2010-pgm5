#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
* Andrew Humphreys Pgm5 CS2010 LEC1003
* 
* 
* 
*
*/


// Global constants
const string FILENAME = "pgm5-1.txt";
const int MAX_REALTORS = 25;

int main()
{
	// Variables
	ifstream in_fs;
	string realtor_names[MAX_REALTORS];
	int realtor_sales_arr[MAX_REALTORS];

	int realtor_most_sales;
	int most_sales;

	int realtor_least_sales;;
	int least_sales;

	int total_sales = 0;

	// Open filestream, and error handling
	in_fs.open("pgm5-1.txt");

	if (!in_fs.is_open())
	{
		cout << "Error reading " << FILENAME << "." << endl;
		return 0;
	}

	// Populate the parralel arrays
	int i = 0;
	while ( !in_fs.eof() && in_fs.good() )
	{
		int raw_realtor_sales;

		in_fs >> realtor_names[i];
		in_fs >> raw_realtor_sales;

		realtor_sales_arr[i] = abs(raw_realtor_sales);

		
		i++;
		if (i > MAX_REALTORS) // Deal with unexpected behavior
			break;
	}


	// Print each realtor, and then find the highest sales

	realtor_most_sales = 0;
	most_sales = realtor_sales_arr[realtor_most_sales];

	realtor_least_sales = 0;
	least_sales = realtor_sales_arr[realtor_least_sales];

	int realtor_number;
	int curr_realtor_sales;

	for (int i = 0;i < MAX_REALTORS;i++)
	{
		// Alternative condition to stop execution
		bool realtor_exists = realtor_names[i].empty();
		if (realtor_exists)
			break;

		realtor_number = i + 1;
		cout << "Realtor " << realtor_number << ", " << realtor_names[i] << ", sold " << realtor_sales_arr[i] << " houses." << endl;

		curr_realtor_sales = realtor_sales_arr[i];
		if (curr_realtor_sales > most_sales)
		{
			realtor_most_sales = i;
			most_sales = curr_realtor_sales;
		}

		if (curr_realtor_sales < least_sales)
		{
			realtor_least_sales = i;
			least_sales = curr_realtor_sales;
		}

		total_sales += curr_realtor_sales;

	}

	realtor_number = realtor_most_sales + 1;
	cout << "The winner is Realtor " << realtor_number << ", " << realtor_names[realtor_most_sales] << ", who sold " << most_sales << " houses." << endl;

	realtor_number = realtor_least_sales + 1;
	cout << "Realtor " << realtor_number << ", " << realtor_names[realtor_least_sales] << ", sold the least number of houses: " << least_sales << endl;

	cout << "And in total all Realtors sold " << total_sales << " houses." << endl;
	


	in_fs.close();




}
