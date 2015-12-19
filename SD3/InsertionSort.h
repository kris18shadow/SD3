#pragma once
#include <iostream>

bool leftIsLess(char* left, char* right)
{
	size_t leftSize = strlen(left), rightSize = strlen(right);
	size_t min = 0;
	
	if (leftSize < rightSize)
		min = leftSize;
	else
		min = rightSize;

	for (size_t i = 0; i < min; i++)
	{
		if (toupper(left[i]) > toupper(right[i]))
			return false;
		if (toupper(left[i]) < toupper(right[i]))
			return true;
	}

	return false;
}

void insertionSort(char** arr, size_t length) 
{
	int j;
	char temp[9];

	for (size_t i = 0; i < length; i++) 
	{
		j = i;

		while (j > 0 && leftIsLess(arr[j], arr[j - 1]) )
		{
			strcpy(temp, arr[j]);
			strcpy(arr[j], arr[j - 1]);
			strcpy(arr[j - 1], temp);
			j--;
		}
	}

	std::cout << "\nSorted names: ";

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; arr[i][j] != '\0'; j++)
		{
			std::cout <<  arr[i][j];
		}
		std::cout << " ";
	}

	std::cout << std::endl;

}