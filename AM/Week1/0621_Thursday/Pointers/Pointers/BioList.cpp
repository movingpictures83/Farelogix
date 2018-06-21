#include "BioList.h"

BioList::BioList(string firstnode) { 
	head = new BioNode(firstnode, NULL); 
}

BioList::~BioList() {
	clear();
}

void BioList::insertFront(string newname) {
	BioNode* tmp = new BioNode(newname, head);
	head = tmp;
}

void BioList::insertBack(string newname, BioNode* start) {
	if (start->getNext() == NULL) start->setNext(new BioNode(newname, NULL));
	else insertBack(newname, start->getNext());
}

void BioList::clear() {
	clear(head);
}
// Remove the entire list from memory
void BioList::clear(BioNode* start) {
	if (start->getNext() == NULL) delete start; // Base Case 1
	else { // Recursive step
		clear(start->getNext());
		delete start;
	}
}