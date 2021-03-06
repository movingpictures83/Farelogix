// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include "Factory.h"

#include "BioAdj.h"
#include "BioAdjMat.h"
#include "BioAdjList.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	// 1. Declare three objects, add nodes and print them.
	// Illegal with a pure virtual function
	/*BioAdj myAdj;
	myAdj.addNode("Na");
	myAdj.addNode("Cl");
	myAdj.print();*/

	BioAdjMat myAdjMat;
	myAdjMat.addNode("Na");
	myAdjMat.addNode("Cl");
	myAdjMat.print();

	BioAdjList myAdjList;
	myAdjList.addNode("Na");
	myAdjList.addNode("Cl");
	myAdjList.print();

	

	// 2. Try setting parent objects to child objects, and vice-versa
	//myAdj = myAdjMat; // Can set a parent = child
	//myAdjMat = myAdj; // Can never set a child = parent
	//myAdj.print(); // Calls parent print function

	// 3. Try setting parent pointers to child objects, and vice-versa
	BioAdj* myAdjPtr = &myAdjMat;
	myAdjPtr->print();
	//myAdjPtr->addEdge(0, 0, 0.3);
	//myAdjPtr->resize(5);
	//myAdjPtr = &myAdj;
	//myAdjPtr->print();
	myAdjPtr = &myAdjList;
	myAdjPtr->print();
	//myAdjPtr->addEdge(1, 1, 0.3);
	//
	//BioAdjMat* myAdjMatPtr = dynamic_cast<BioAdjMat*>(&myAdj); // Can't set a child pointer equal to a parent object
	//myAdjMatPtr->resize(5);
	//myAdjMatPtr->print();

	// 4. Create methods for adding edges.  How do we handle this in BioAdj?


	// 5. Use The Factory Method to create a customized BioAdj
	string choice;
	cout << "Enter your choice:";
	cin >> choice;
	/*if (choice.compare("BioAdjMat") == 0)
		myAdjPtr = new BioAdjMat();
	else
		myAdjPtr = new BioAdjList();
	myAdjPtr->print();*/
	
	BioAdj* myAdj = Factory::getInstance()->create(choice);
	myAdj->addNode("Na");
	myAdj->addNode("Cl");
	myAdj->print();
	return 0;
}

