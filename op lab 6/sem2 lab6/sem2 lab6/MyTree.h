#pragma once
#include<iostream>
using namespace std;
struct Node {
	string inf;
	Node* left, * right;
	Node(string x) : inf(x), left(NULL), right(NULL) {};
};
class Tree {
	Node* root;
public:
	Tree() :root(NULL) {};
	Node* makeTree(string m[], int from, int n);
	void printTree(const string& prefix, const Node* node, bool isLeft);
	void level(Node* root, string m[], int from);
};