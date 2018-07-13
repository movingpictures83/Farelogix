#pragma once

#include <map>
#include <string>
#include <iostream>
using std::map;
using std::string;
using std::cout;
using std::endl;

#include "Register.h"
#include "BioAdj.h"



class BioAdjMat : public BioAdj
{
private:
	vector<vector<float> > network;

public:
	BioAdjMat() {}
	BioAdjMat(vector<string>& n);
    void addNode(string s); 
	void print() { cout << "BIOADJMAT OF " << nodeNames.size() << " NODES." << endl; }
	void resize(int s);
	void addEdge(int i, int j, float f);

public:
	static BioAdj* make() { return new BioAdjMat; }
	static Register reg;
};
