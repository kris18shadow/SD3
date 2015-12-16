#include <iostream>
#include "Solver.h"

int main()
{	//
	//READING T:
	//
	unsigned T;
	std::cin >> T;

	Solver X(T);
	if (X.initiateSolving() == 0)
		return 0;
	else
		return 1;

	/*
	for (size_t i = 0; i < T; i++)
	{

		//
		//READING N AND Q:
		//
		unsigned N, Q;

		while (true)
		{
			std::cin >> N >> Q;
			if (N > 1000000 || Q > 500000)
			{
				std::cerr << "Bad input!\nN must be <= 1 000 000 "
					<< "and Q must be <= 500 000! Try again:\n";
				continue;
			}
			else
				break;
		}

		//
		//READING NAMES:
		//
		char buffer[1028];

		std::cin.ignore();
		std::cin.getline(buffer, 1027, '\n');

		//check input:
		size_t nameCount = 1;

		for (size_t i = 0; i < strlen(buffer); i++)
			if (buffer[i] == ' ')
				nameCount++;

		if (nameCount != N)
		{
			std::cerr << "N and number of names do not match!\n";
			return 1;
		}
		
		//
		//CREATING 2D ARRAY:
		//

		//dinamically allocating 2D array:
		char** names = new char*[N];
		for (size_t i = 0; i < N; i++)
			names[i] = new char[9];

		//transfering names in array:
		size_t offset = 0;

		for (size_t i = 0; i < N; i++)
		{
			size_t currPos = 0;
			for (size_t j = offset; j < strlen(buffer); j++)
			{
				if (j == strlen(buffer) - 1)
				{
					names[i][currPos + 1] = '\0';
				}
				if (buffer[j] == ' ')
				{
					names[i][currPos] = '\0';
					offset = j + 1;
					break;
				}
				else
				{
					names[i][currPos] = buffer[j];
					currPos++;
				}
			}
		}

		//INSERTION SORT:
		insertionSort(names, N);

		
		//ENTER COMMAND:
		size_t leftBorder = 0, rightBorder = N;

		for (size_t i = 0; i < Q; i++)
		{
			char command[64];
			std::cin.sync();
			std::cin.getline(command, 63, '\n');
			std::cout << "@ " << command << " @";

			if (strncmp(command, "ENTER", 4) == 0)
			{
				size_t currPos = 5;
				char firstArg[8], secondArg[8];

				size_t x = 0;
				while (command[currPos] < 64 && command[currPos] != ' ')
				{
					if (command[currPos] > '0' && command[currPos] < '9')
					{
						firstArg[x] = command[currPos];
						x++;
					}
					currPos++;
				}

				size_t y = 0;
				while (currPos < 64 && command[currPos] != '\0')
				{
					if (command[currPos] > '0' && command[currPos] < '9')
					{
						secondArg[y] = command[currPos];
						y++;
					}
					currPos++;
				}

				leftBorder = atoi(firstArg);
				rightBorder = atoi(secondArg);
			}
			else
			if (strncmp(command, "QUERY", 4) == 0)
			{
				size_t currPos = 6;
				char arg[8];

				size_t x = 0;
				while (currPos < 64 && command[currPos] != '\0')
				{
					arg[x] = command[currPos];
					x++;
					currPos++;
				}

				size_t matchCounter = 0;
				for (size_t i = leftBorder; i < rightBorder; i++)
				{
					if (strncmp(arg, names[i],x) == 0)
						matchCounter++;
				}
				std::cout << matchCounter << std::endl;
			}
			else
			{
				std::cerr << "Wrong input! Available commands are ENTER and QUERY!\n";
			}
		}
		
		//TEST:
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < strlen(names[i]); j++)
			{
				std::cout << names[i][j];
			}
			std::cout << std::endl;
		}
	}
	*/

	return 0;
}