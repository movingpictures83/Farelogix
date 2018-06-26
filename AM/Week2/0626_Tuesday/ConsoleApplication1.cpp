// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Factory.h"
//#include "BioAdjMat.h"
//#include "BioAdjList.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	// A::stuff["B"] is itself a function
	string choice;
	cout << "Enter BioAdjMat or BioAdjList:";
	cin >> choice;
	
	BioAdj* myAdj = Factory::stuff[choice]();
	myAdj->print();
	return 0;
}

