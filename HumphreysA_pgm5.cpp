#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
* Andrew Humphreys Pgm5 CS2010 LEC1003
* Purpose: To provide a basic analysis of data reguarding realtor sales.
* Input: A raw-text file containing up to 25 lines of realtor name followed by number of sales seperated by a space.
* Processing: The program catches typos created by accidental negative numbers,
*	Finds the realtor and the asscioated max and min number of sales,
*	and calculates a total sum of sales.
* Output: Outputs to console all of the realtors and their sales, and the above processed info (min, max, total sales).
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
	string realtor_names_arr[MAX_REALTORS];
	int realtor_sales_arr[MAX_REALTORS];

	int top_realtor;
	int most_sales;

	int bottom_realtor;;
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

		in_fs >> realtor_names_arr[i];
		in_fs >> raw_realtor_sales;

		realtor_sales_arr[i] = abs(raw_realtor_sales);

		
		i++;
		if (i > MAX_REALTORS) // Deal with unexpected behavior
			break;
	}

	in_fs.close();
	// Print each realtor, and then find the highest sales

	top_realtor = 0;
	most_sales = realtor_sales_arr[top_realtor];

	bottom_realtor = 0;
	least_sales = realtor_sales_arr[bottom_realtor];

	int realtor_id;
	int curr_realtor_sales;

	// Preform processing on data:
	for (int i = 0;i < MAX_REALTORS;i++)
	{
		// Alternative condition to stop execution
		bool realtor_exists = realtor_names_arr[i].empty();
		if (realtor_exists)
			break;

		realtor_id = i + 1;
		cout << "Realtor " << realtor_id << ", " << realtor_names_arr[i] << ", sold " << realtor_sales_arr[i] << " houses." << endl;

		// Calculate max, min and last total
		curr_realtor_sales = realtor_sales_arr[i];
		if (curr_realtor_sales > most_sales)
		{
			top_realtor = i;
			most_sales = curr_realtor_sales;
		}

		if (curr_realtor_sales < least_sales)
		{
			bottom_realtor = i;
			least_sales = curr_realtor_sales;
		}

		total_sales += curr_realtor_sales;

	}


	// Last provide program output.
	realtor_id = top_realtor + 1;
	string top_realtor_name = realtor_names_arr[top_realtor];
	cout << "The winner is Realtor " << realtor_id << ", " << top_realtor_name << ", who sold " << most_sales << " houses." << endl;

	realtor_id = bottom_realtor + 1;
	string bottom_realtor_name = realtor_names_arr[bottom_realtor];
	cout << "Realtor " << realtor_id << ", " << bottom_realtor_name << ", sold the least number of houses: " << least_sales << endl;

	cout << "And in total all Realtors sold " << total_sales << " houses." << endl;
	




}
