// bkwiatkowski_HW3_AAE
//The purpose of this program is to determine how many layers of glass are necessary to maintain equilibrium for a solar panel system.

#include <iostream>
#include <cmath>

int main()
{
	//initializing cout so that the program will print to the command window
	using std::cout;
	
	//Initializing given test parameters for the assignment
	float Pi = 925;
	float Po = 750;
	float t = .98;
	float Tc = 353;
	float Ta = 283;

	//initializing function values (does not affect the outcome of program in any realistic case)
	float Pa = 1;
	float PL = 1;

	//Using the equations given in the notes it is seen that the below value in equation PL is a constant
	//and can be determined beforehand for code syntax and reusability
	float TempDiff = pow(Tc, 4) - pow(Ta, 4);
	float BoltConst = 5.67 * (pow(10,-8));
	float value = TempDiff * BoltConst;

	//initializing number of glass panes to 1
	int n = 1;

	//Loop that determines how many glass panes are needed, will continue to run until the value of 
	//Pa is more or equal than the value of Po +PL
	while (Pa < (Po + PL)) {
		
		//Functions that are used in the equilibrium evaluation
		Pa = pow(t, n) * Pi;
		PL = (value / (n + 1));

		//printing in command window for simplicity and ease of viewing
		cout << "n: " << n << "\n";
		cout << "LHS: " << Pa << "\nRHS: " << PL + Po <<"\n \n";

		//Function to determine whether the system is done or not.
		//Prints a final message of how many panes of glass are required
		if (Pa >= Po + PL) {
			cout << "The system requires: " << n << " planes of glass to maintain equilibrium.\n";
			break;
		}

		//increases the number of panes if the above condition is not met
		else {
			n++;
		}
	}
}
