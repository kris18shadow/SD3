#include <iostream>
#include "Solver.h"

int main()
{	//
	//READING T:
	//
	unsigned T;
	std::cout << "Enter T: ";
	std::cin >> T;

	Solver X(T);
	if (X.initiateSolving() == 0)
		return 0;
	else
		return 1;


	return 0;
}