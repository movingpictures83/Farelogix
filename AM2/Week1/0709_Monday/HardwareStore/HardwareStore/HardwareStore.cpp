// HardwareStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>  // including the code for STL string
//#include <fstream>
#include <iostream> // including the code for STL cin and cout
using std::string;  // STL string
//using std::ifstream;
//using std::ofstream;
using std::cout; // STL cout
using std::cin;  // STL cin
using std::endl; // STL endl
//using std::ios;
using std::fixed;



int main()
{
	constexpr int MAXFILENAMESIZE = 50;
	const char* prefix = "C:\\Users\\student\\source\\repos\\";
	//const int MAXFILENAMESIZE = 50;
	// Read File
	// Arrays
	/*string products[3];
	unsigned short quantity[3];
	float prices[3];
	float totals[3];*/
	// Get input file name
	printf("Enter your input file name:");
	//cout << "Enter your input file name:";
	char filename[MAXFILENAMESIZE+1];
	//string filename;
	scanf_s("%s", filename, MAXFILENAMESIZE + 1);
	//cin >> filename; 

	char* inputfilename = (char*)malloc(strlen(prefix) + MAXFILENAMESIZE + 1);
	strcpy_s(inputfilename, strlen(prefix)+1, prefix);  // inputfilename = prefix
	strcat_s(inputfilename, strlen(prefix) + MAXFILENAMESIZE + 1, filename); // inputfilename += filename
	//char* inputfilename = new char[strlen(prefix) + MAXFILENAMESIZE + 1];
	//filename.insert(0, );

	printf("Enter your output file name:");
	//cout << "Enter your output file name:";
	scanf_s("%s", filename, MAXFILENAMESIZE + 1);

	char* outputfilename = (char*)malloc(strlen(prefix) + MAXFILENAMESIZE + 1);
	strcpy_s(outputfilename, strlen(prefix) + 1, prefix);  // outputfilename = prefix
	strcat_s(outputfilename, strlen(prefix) + MAXFILENAMESIZE + 1, filename); // outputfilename += filename
	//string outputfilename;
	//cin >> outputfilename;
	//outputfilename.insert(0, "C:\\Users\\student\\source\\repos\\");


	// Open the file
	FILE* inputfile, *outputfile;
	fopen_s(&inputfile, inputfilename, "r");
	fopen_s(&outputfile, outputfilename, "w");

	//ifstream inputfile(inputfilename, ios::in); // Input mode only
	//if (inputfile.fail()) cout << "ERROR" << endl;

	//ofstream outputfile(outputfilename, ios::out); // Output mode only
	char ch;
	fprintf(outputfile, "%-50s %11s\n", "Product", "Total Sales");
	char product[50];
	unsigned short quantity;
	float price;
	do {
		//int q;
		ch = fscanf_s(inputfile, "%s\t%hu\t%f", product, 50, &quantity, &price);  // %s=string, %d=integer, %f=float
		//quantity = (short)q;
		if (ch != EOF) {
			fprintf(outputfile, "%-50s $%10.2f\n", product, quantity*price);
		}
	} while (ch != EOF);


	// First line
	/*inputfile >> products[0];
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
	*/
	free(inputfilename);
	free(outputfilename);
	fclose(inputfile);
	fclose(outputfile);
	//delete[] inputfilename;
    return 0;
}

