// HardwareStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::fixed;
using std::ofstream;

int main()
{
	// Get inputfile from the user
	string inputfile;
	cout << "Enter your input file:";
	cin >> inputfile;
	inputfile = "C:\\Users\\student\\source\\repos\\" + inputfile;

	// Get outputfile from the user
	string outputfile;
	cout << "Enter your output file:";
	cin >> outputfile;
	outputfile = "C:\\Users\\student\\source\\repos\\" + outputfile;

	// Open the inputfile
	ifstream infile(inputfile, ios::in); // Open only for input
	
	// Open the outputfile
	ofstream outfile(outputfile, ios::out);

	// First line
	string products[3];
	short quantities[3];
	float prices[3];
	infile >> products[0] >> quantities[0] >> prices[0];

	// Second line
	infile >> products[1] >> quantities[1] >> prices[1];

	// Third line
	infile >> products[2] >> quantities[2] >> prices[2];

	// Output
	// First Line
	outfile.width(50);
	outfile.flags(ios::left);
	outfile << products[0];
	outfile.width(8);
	outfile.flags(ios::right);
	outfile.precision(2);
	outfile << "$" << fixed << quantities[0] * prices[0] << endl;

	// Second Line
	outfile.width(50);
	outfile.flags(ios::left);
	outfile << products[1];
	outfile.width(8);
	outfile.flags(ios::right);
	outfile << "$" << fixed << quantities[1] * prices[1] << endl;

	// Third Line
	outfile.width(50);
	outfile.flags(ios::left);
	outfile << products[2];
	outfile.width(8);
	outfile.flags(ios::right);
	outfile << "$" << fixed << quantities[2] * prices[2] << endl;
    return 0;
}

