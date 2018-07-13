#include "stdafx.h"
#include "BioAdjMat.h"

BioAdjMat::BioAdjMat(vector<string>& n) : BioAdj(n) {
	resize(n.size());
}

void BioAdjMat::resize(int s) {
	// Resize each row, and each column
	network.resize(s);
	for (int i = 0; i < network.size(); i++)
		network[i].resize(s);
}

void BioAdjMat::addNode(string s) 
{ 
	BioAdj::addNode(s);  
	resize(network.size() + 1);
}

void BioAdjMat::addEdge(int i, int j, float f) {
	network[i][j] = f;
}

Register BioAdjMat::reg = Register(string("BioAdjMat"), &BioAdjMat::make);