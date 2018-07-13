#include "stdafx.h"
#include "BioAdjList.h"

BioAdjList::BioAdjList(vector<string>& n) : BioAdj(n) {
	network.resize(n.size());
}

void BioAdjList::addNode(string s)
{
	BioAdj::addNode(s);
	network.resize(network.size() + 1);
}

void BioAdjList::addEdge(int i, int j, float f) {
	network[i].emplace_back(nodeNames[j], f);
}


Register BioAdjList::reg = Register(string("BioAdjList"), &BioAdjList::make);