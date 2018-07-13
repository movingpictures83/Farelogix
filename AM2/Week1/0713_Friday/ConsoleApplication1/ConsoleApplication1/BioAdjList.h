#pragma once

#include <list>
#include <utility>
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::list;
using std::pair;

#include "Register.h"
#include "BioAdj.h"

class BioAdjList : public BioAdj
{
private:
	vector<list<pair<string, float> > > network;
public:
	BioAdjList() {}
	BioAdjList(vector<string>& n);
	void addNode(string s);
	void print() { cout << "BIOADJLIST OF " << nodeNames.size() << " NODES." << endl; }
	void addEdge(int i, int j, float f);

public:
	static BioAdj* make() { return new BioAdjList; }
	static Register reg;
};

