#include "Solver.h"
#include "InsertionSort.h"

Solver::Solver(unsigned T)
{
	this->T = T;
}

Solver::~Solver()
{
	for (size_t i = 0; i < N; i++)
	{
		delete[] names[i];
	}
	delete[] names;
}

void Solver::inputNQ()
{
	//
	//READING N AND Q:
	//

	while (true)
	{
		std::cout << "\nEnter N and Q: ";
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
}

bool Solver::inputNames()
{
	//
	//READING NAMES:
	//
	char buffer[1028];
	std::cout << "Enter names: ";

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
		return false;
	}

	//
	//CREATING 2D ARRAY:
	//

	//dinamically allocating 2D array:
	names = new char*[N];
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

	return true;
}

void Solver::commandSequence()
{
	//ENTER COMMAND:
	std::cout << "\nYou can enter " << Q << " commands:" << std::endl;
	size_t leftBorder = 0, rightBorder = N - 1;
	
	for (size_t i = 0; i < Q; i++)
	{
		std::cout << "\nCommand " << i + 1 << " out of " << Q << " :" << std::endl;
		char command[64];
		std::cin.sync();
		std::cin.getline(command, 63, '\n');

		if (strncmp(command, "ENTER", 4) == 0)
		{
			size_t currPos = 6;
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
			if (leftBorder > N)
			{
				std::cerr << "\nWrong Input! Left Border is bigger than N!" << std::endl;
				leftBorder = 0;
			}
			rightBorder = atoi(secondArg);
			if (rightBorder > N)
			{
				std::cerr << "\nWrong Input! Right Border is bigger than N!" << std::endl;
				rightBorder = N - 1;
			}	

			std::cout << "Entered range [" << leftBorder << ";" 
				      << rightBorder << "]" << std::endl;
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
				for (size_t i = leftBorder; i <= rightBorder; i++)
				{
					if (strncmp(arg, names[i], x) == 0)
						matchCounter++;
				}
				std::cout << matchCounter << std::endl;
			}
			else
			{
				std::cerr << "Wrong input! Available commands are ENTER and QUERY!" << std::endl;
			}
	}

}

int Solver::initiateSolving()
{
	for (size_t i = 0; i < T; i++)
	{
		//READING N and Q:
		inputNQ();

		//READING AND STORING NAMES:
		if (!inputNames())
			return 1;

		//INSERTION SORTING NAMES:
		insertionSort(names, N);

		//COMMANDS:
		commandSequence();
	}

	return 0;
}