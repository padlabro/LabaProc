#include <fstream>
#include <iostream>

using namespace std;

void CheckInputFile(ifstream &ifst)
{
	if (!ifst)
	{
		cerr << "Error: no input file!" << endl;
		exit(1);
	}
}

void CheckWrongInput(ifstream &ifst)
{
	if (ifst.fail())
	{
		cout << "Wrong input!" << endl;
		exit(1);
	}
}

void CheckOutputFile(ostream &ofst)
{
	if (!ofst)
	{
		cerr << "Error: no output file!" << endl;
		exit(1);
	}
}

void CheckAge(int age)
{
	if (age < 0)
	{
		cout << "Incorrect input age." << endl;
		exit(1);
	}
}