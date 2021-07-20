/****************************************************
* Author: Braeden Kilburn
*
* Date Created: 20 February 2020
*
* Description: Calculate a user's change to return for a purchase
*
* UPDATE (07/19/2021): 
* 	There are a lot of problems with this code, after over a year
* 	of coding experience, I can see the errors and will fix it... one day.
****************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// All currency converted to pennies
const double quarters = 0.25 * 100;
const double dimes = 0.1 *100;
const double nickels = 0.05 * 100;
const double pennies = 0.01 * 100;
const double singles = 1.0 * 100;
const double fives = 5.0 * 100;
const double tens = 10.0 * 100;
const double twenties = 20.0 * 100;

int main() 
{
	double amountDue {0};
	double amountPayed {0};
	
	// Prompt the user to input the amount owed and amount paid
	cout << setw(40) << setfill('*') << "" << endl;
	cout << "How much does the guest owe? $";
	cin >> amountDue;
	cout << "How much did the guest pay? $";
	cin >> amountPayed;
	cout << setw(40) << "" << endl << endl;
	
	// Test if they paid enough money to cover the cost
	if (amountDue > amountPayed)
	{
		cout << "The guest did not pay the total amount due." << endl << endl;
		return 0;
	} 
	else if (amountDue == amountPayed)
	{
		cout << "No change necessary!" << endl << endl;
		return 0;
	}
	
	// Output the change owed in dollars and cents ($x.xx)
	double changeDue { amountPayed - amountDue };
	cout << "Change Due: $" << changeDue << endl << endl;
	
	
	double pennyAmountDue {changeDue * 100};
	
	/***************************************************************************
	 *  Simply, the math here is that we take our total and convert it to
	 *  pennies. Once we have the total in pennies, we divide the amount of 
	 *  pennies by the twenties (also in penny form) to see how many 
	 *  twenties would fit in the total. Then, we take remainder of the pennies 
	 *  that were not covered by the twenties and divide that by the tens. We 
	 *  repeat this process until we exhaust our change and thus exhaust
	 *  the change due as well.
	 * 
	 *  Also, fmod() is used to return the floating-point remainder.
	 **************************************************************************/
	 
	// Change due in TWENTIES
	double changeDueInTwenties {pennyAmountDue / twenties};
	double changeRemaining1 {fmod(pennyAmountDue, twenties)};
	
	// Change due in TENS
	double changeDueInTens {changeRemaining1 / tens};
	double changeRemaining2 {fmod(changeRemaining1, tens)};
	
	// Change due in FIVES
	double changeDueInFives {changeRemaining2 / fives};
	double changeRemaining3 {fmod(changeRemaining2, fives)};
	
	// Change due in SINGLES
	double changeDueInSingles {changeRemaining3 / singles};
	double changeRemaining4 {fmod(changeRemaining3, singles)};
	
	// Change due in QUARTERS
	double changeDueInQuarters {changeRemaining4 / quarters};
	double changeRemaining5 {fmod(changeRemaining4, quarters)};
	
	// Change due in DIMES
	double changeDueInDimes {changeRemaining5 / dimes};
	double changeRemaining6 {fmod(changeRemaining5, dimes)};
	
	// Change due in NICKELS
	double changeDueInNickels {changeRemaining6 / nickels};
	double changeRemaining7 {fmod(changeRemaining6, nickels)};
	
	// Change due in PENNIES
	double changeDueInPennies {changeRemaining7 / pennies};
	
	// Output the expected change
	cout << "The guest would get back: " << static_cast <int> (changeDueInTwenties) << " x $20" << endl; 
	cout << setw(27) << setfill(' ') << static_cast <int> (changeDueInTens) << " x $10" << endl;
	cout << setw(27) << static_cast <int> (changeDueInFives) << " x $5" << endl;
	cout << setw(27) << static_cast <int> (changeDueInSingles) << " x $1" << endl;
	
	// Outputs are conditional here for grammar purposes
	if (static_cast <int> (changeDueInQuarters) > 1 || static_cast <int> (changeDueInQuarters) == 0)
	{
		cout << setw(27) << static_cast <int> (changeDueInQuarters) << " x Quarters" << endl;
	}
	else
	{
		cout << setw(27) << static_cast <int> (changeDueInQuarters) << " x Quarter" << endl;
	}
	
	if (static_cast <int> (changeDueInDimes) > 1 || static_cast <int> (changeDueInDimes) == 0)
	{
		cout << setw(27) << static_cast <int> (changeDueInDimes) << " x Dimes" << endl;
	}
	else
	{
		cout << setw(27) << static_cast <int> (changeDueInDimes) << " x Dime" << endl;
	}
	
	if (static_cast <int> (changeDueInNickels) > 1 || static_cast <int> (changeDueInNickels) == 0)
	{
		cout << setw(27) << static_cast <int> (changeDueInNickels) << " x Nickels" << endl;
	}
	else 
	{
		cout << setw(27) << static_cast <int> (changeDueInNickels) << " x Nickel" << endl;
	}
	
	if (static_cast <int> (changeDueInPennies) > 1 || static_cast <int> (changeDueInPennies) == 0)
	{
		cout << setw(27) << static_cast <int> (changeDueInPennies) << " x Pennies" << endl << endl;
	}
	else
	{
		cout << setw(27) << static_cast <int> (changeDueInPennies) << " x Penny" << endl << endl;
	}
	
	return 0;
}