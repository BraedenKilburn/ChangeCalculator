/************************************************
* Author: Braeden Kilburn
*
* Date Created: 20 February 2020
*
* Description: Calculate a user's change to return for a purchase
*
************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

const double quarters = 0.25;
const double dimes = 0.1;
const double nickels = 0.05;
const double pennies = 0.01;
const double singles = 1.0;
const double fives = 5.0;
const double tens = 10.0;
const double twenties = 20.0;

int main() 
{
	double amountDue {0};
	double amountPayed {0};
	
	cout << setw(40) << setfill('*') << "" << endl;
	cout << "How much the customer owe? $";
	cin >> amountDue;
	cout << "How much did the customer pay? $";
	cin >> amountPayed;
	cout << setw(40) << "" << endl << endl;
	
	if (amountDue > amountPayed)
	{
		cout << "The guest did not pay the total amount due." << endl << endl;
	}
	else
	{
		double changeDue { amountPayed - amountDue };
		cout << "Change Due: $" << changeDue << endl;
	}
	
	return 0;
}