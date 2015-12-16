#pragma once
#include <iostream>


class Solver
{
private:
	unsigned T;
	unsigned N, Q;
	char** names;

	void inputNQ();
	bool inputNames();
	void commandSequence();
public:
	Solver(unsigned T);
	int initiateSolving();
	~Solver();
};
