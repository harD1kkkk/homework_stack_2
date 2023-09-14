#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	string text;
	Node* next;

	Node();
	Node(string text);
	Node(string text, Node* next);
};