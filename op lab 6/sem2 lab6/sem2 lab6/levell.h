#pragma once
#include"MyTree.h"
struct levelNode {
	Node* trans;
	levelNode* next;
};
class levell {
	levelNode* Head;
public:
	levell() { Head = NULL; }
	int isEmpty();
	void addlevel(Node* tmp);
	Node* dellevel();
};