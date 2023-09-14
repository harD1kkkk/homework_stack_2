#include "Node.h"
Node::Node() {
	text = "";
	next = nullptr;
}

Node::Node(string text) {
	this->text = text;
}

Node::Node(string text, Node* next) {
	this->text = text;
	this->next = next;
}