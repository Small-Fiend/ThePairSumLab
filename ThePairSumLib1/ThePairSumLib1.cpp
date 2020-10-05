// ThePairSumLib1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "ThePairSumLib.h"

const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const std::string ABOUT_MESSAGE = "The least sum of pair";
const std::string CONTINUE_MESSAGE =
"Continue? (Y/N)>";
const std::string INCORRECT_MESSAGE =
"Input is incorrect. Try again>";
const std::string INPUT_MESSAGE = "Input size of list>";
const std::string INPUT_MESSAGE_VECT = "Input a list of integer>";
const std::string OUT_OF_BOUNDS_MESSAGE =
"This number is out of bounds";
const std::string OUTPUT_MESSAGE = "Result: ";
const std::string SKIP_CHARACTERS = " ";

void ClearInputStream(std::istream& in)
{
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF)
	{
		in.get();
	}
}

int Seek(std::istream& in)
{
	while (in.peek() != EOLN && SKIP_CHARACTERS.find((char)in.peek()) != std::string::npos)
	{
		in.get();
	}
	return in.peek();
}

bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <= RIGHT_BOUND);
	if (!ok)
	{
		std::cout << OUT_OF_BOUNDS_MESSAGE << " [" << LEFT_BOUND << ", " << RIGHT_BOUND << "]" << std::endl;
	}
	return ok;
}

int ReadInt(std::istream& in)
{
	std::cout << INPUT_MESSAGE;
	int ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || !CheckBounds(ans))
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans;
}

void ReadVect(std::istream& in, int* vect, int& n)
{
	std::cout << INPUT_MESSAGE_VECT;
	int elem;
	int k = 0;
	in >> vect[k];
	while (Seek(in) != EOLN || k < n - 1)
	{
		while (!in || !CheckBounds(vect[k]) || k == (n - 1) || (Seek(in) == EOLN && k < n - 1))
		{
			ClearInputStream(in);
			std::cout << INCORRECT_MESSAGE;
			k = 0;
			in >> vect[k];
		}
		in >> vect[++k];
	}
}

bool NeedContinue(std::istream& in)
{
	std::cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans != YES_CHAR && ans != NO_CHAR)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}

int main()
{
	std::cout << ABOUT_MESSAGE << std::endl;
	bool cont = true;
	while (cont)
	{
		int n = ReadInt(std::cin);
		int* vect = new int[n];
		ReadVect(std::cin, vect, n);
		std::cout << OUTPUT_MESSAGE << Sum(&vect[0], n) << std::endl;
		delete[] vect;
		cont = NeedContinue(std::cin);
	}
	return 0;
}


