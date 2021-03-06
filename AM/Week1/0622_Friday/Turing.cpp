// Turing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CSVReader.h"
#include <string>
#include "../../BioNetException.h"
#include "../../Reader.h"
using std::cout;
using std::endl;

int main()
{
	string fileName = "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\mostextreme\\mostextreme.csv";
	//Reader read(fileName);

	CSVReader csvReader(/*fileName*/(string)"csv");

	// Objects
	//Reader read2 = CSVReader(fileName);
	//CSVReader csv2 = Reader(fileName);  Child to parent, no

	// Pointers
	Reader* read3 = NULL;
	string choice;
	cout << "Which reader do you have?";
	cin >> choice;
	if (choice.compare("CSV") == 0)
		read3 = &csvReader;
	
	//Reader* read2 = (Reader*) &csvReader;
	//CSVReader* csv2 =  &read;   ERROR, CANNOT SET CHILD POINTER TO PARENT OBJECT

	BioNet bioNet(-0.5, 0.5, true);
	//read.readFile(bioNet);
	csvReader.readFile(bioNet, fileName);
	//csvReader.f(); // No, ambiguous
	cout << "GOT HERE" << endl;
	read3->readFile(bioNet, fileName);
	//csv2->readFile(bioNet);
}
/*
	//Verify node names
	if (bioNet.getNode(0).compare("\"A\"") != 0) {
		cout << "Error on node A" << endl;
	}

	if (bioNet.getNode(1).compare("\"B\"") != 0) {
		cout << "Error on node B" << endl;
	}

	if (bioNet.getNode(2).compare("\"C\"") != 0) {
		cout << "Error on node C" << endl;
	}

	if (bioNet.getNode(3).compare("\"D\"") != 0) {
		cout << "Error on node D" << endl;
	}

	if (bioNet.getNode(4).compare("\"E\"") != 0) {
		cout << "Error on node E" << endl;
	}

	//Verify Edge's Weight
	float adjMatrix[5][5] = { 
							{ 0.5,-0.5,-0.5,-0.5,-0.5 },
							{ -0.5,0.5,0.5,0.5,0.5 }, 
							{ -0.5,0.5,0.5,0.5,0.5 }, 
							{ -0.5,0.5,0.5,0.5,0.5 }, 
							{ -0.5,0.5,0.5,0.5,0.5 } 
	};

	for (int row = 0; row < 5; ++row) 
		for (int col = 0; col < 5; ++col) 
			if (!(bioNet.getEdge(row, col) > adjMatrix[row][col] - .001 && bioNet.getEdge(row, col) < adjMatrix[row][col] + .001))
				cout << "Edge at " << row << " ," << col << " is incorrect. Expected: " << bioNet.getEdge(row, col) << " Recieved: "  << adjMatrix[row][col] << endl;
	//Test Exceptions

	try 
	{
		string fakeFile = "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\FakeFile\\fakefile.csv";
		CSVReader csvReader(fakeFile);
		BioNet fakeBioNet(-0.5, 0.5, true);
		csvReader.readFile(fakeBioNet);
		cout << "Shoud have revieved an error for opening a non existant file but did not" << endl;
	}
	catch (BioNetException & bioexcept)
	{
		cout << "Recieved expected exception for bad file\n" << bioexcept.what() <<  endl;
	}

	try
	{
		string brokenFile = "C:\\Users\\student\\Desktop\\BioNet\\data\\Basic\\BrokenFile\\brokenfile.csv";
		CSVReader csvReader(brokenFile);
		BioNet brokenBioNet(-0.5, 0.5, true);
		csvReader.readFile(brokenBioNet);
		cout << "Shoud have revieved an error for opening an improperly formated file but did not" << endl;

	}
	catch (BioNetException & bioexcept)
	{
		cout << "Recieved expected exception for improperly formatted file file:\n" << bioexcept.what() << endl;

	}

    return 0;
}
*/