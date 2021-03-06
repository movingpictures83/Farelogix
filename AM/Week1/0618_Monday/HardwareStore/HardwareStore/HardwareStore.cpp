// HardwareStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fixed;

int main()
{
	// Read File
	// Arrays
	string products[3];
	short quantity[3];
	float prices[3];
	float totals[3];
	// Get input file name
	cout << "Enter your input file name:";
	string filename;
	cin >> filename; 
	filename.insert(0, "C:\\Users\\student\\source\\repos\\");

	cout << "Enter your output file name:";
	string outputfilename;
	cin >> outputfilename;
	outputfilename.insert(0, "C:\\Users\\student\\source\\repos\\");

	// Open the file
	ifstream inputfile(filename, ios::in); // Input mode only
	if (inputfile.fail()) cout << "ERROR" << endl;

	ofstream outputfile(outputfilename, ios::out); // Output mode only

	// First line
	inputfile >> products[0];
	inputfile >> quantity[0];
	inputfile >> prices[0];

	// Second line
	inputfile >> products[1];
	inputfile >> quantity[1];
	inputfile >> prices[1];


	// First line
	inputfile >> products[2];
	inputfile >> quantity[2];
	inputfile >> prices[2];

	// Column width = 50
	outputfile.flags(ios::left); // Left justify text
	outputfile.precision(2); // Two digits of precision
	outputfile.width(50);
	outputfile << "Product";
	outputfile.flags(ios::right); // Left justify text
	outputfile.width(11);
	outputfile << "Total Sales" << endl;
	outputfile << endl;

	// First line
	totals[0] = quantity[0] * prices[0];
	outputfile.width(50);
	outputfile.flags(ios::left); // Left justify text
	outputfile << products[0];
	outputfile.width(1);
	outputfile << "$";
	outputfile.flags(ios::right); // Left justify text
	outputfile.width(11);
	outputfile << fixed << totals[0];
	outputfile << endl;

	// Second line
	totals[1] = quantity[1] * prices[1];
	outputfile.flags(ios::left); // Left justify text
	outputfile.width(50);
	outputfile << products[1];
	outputfile.width(1);
	outputfile << "$";
	outputfile.width(11);
	outputfile.flags(ios::right); // Left justify text
	outputfile << fixed << totals[1];
	outputfile << endl;

	// Third line
	outputfile.width(50);
	outputfile.flags(ios::left); // Left justify text
	outputfile << products[2];
	outputfile.width(1);
	totals[2] = quantity[2] * prices[2];
	outputfile << "$";
	outputfile.width(11);
	outputfile.flags(ios::right); // Left justify text
	outputfile << fixed << totals[2];
	outputfile << endl;

	// Total
	outputfile.width(50);
	outputfile.flags(ios::left); // Left justify text
	outputfile << "Total";
	outputfile.width(1);
	outputfile << "$";
	outputfile.width(11);
	outputfile.flags(ios::right); // Left justify text
	outputfile << fixed << totals[0]+totals[1]+totals[2];
	outputfile << endl;
    return 0;
}

