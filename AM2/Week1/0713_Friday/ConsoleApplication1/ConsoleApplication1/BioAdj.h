#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

class BioAdj {
protected:
	vector<string> nodeNames;	
public:
	BioAdj() {}
	BioAdj(vector<string>& n) { nodeNames = n; }
	string getNode(int i) { return nodeNames[i]; }
	virtual void addNode(string s) { nodeNames.push_back(s); }
	virtual void print() { cout << "BIOADJ OF " << nodeNames.size() << " NODES." << endl; }
	virtual void addEdge(int i, int j, float f) = 0;
};
