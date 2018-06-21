#pragma once

#include <vector>

#include "BioNode.h"

class BioList {

public:
	// A member of the adjacency lists
	BioNode * head;
	int x;
public:
	BioList(string firstnode); 
	~BioList();
	void insertFront(string newname);
	void insertBack(string newname, BioNode* start);
	void clear();
	void clear(BioNode* start);
	
};