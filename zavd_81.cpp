// zavd_81.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
using namespace std;

void addText(Node*& head, string text) {
	Node* n = new Node(text);

	if (head == nullptr) {
		head = n;
		return;
	}

	n->next = head;
	head = n;
}

void deleteText(Node*& head1, Node*& head2) {
	head2 = head1;
	cout << "Deleted: " << head1->text << endl;
	head1 = head1->next;
}

void undo(Node*& head1, Node*& head2) {
	head1 = head2;
	head2 = nullptr;
	cout << "Returned: " << head1->text << endl;
}

void redo(Node*& head1, Node*& head2) {
	head2 = head1;
	head1 = head1->next;
	cout << "Repeating the user's action: " << endl;
}

void display(Node*& head) {
	Node* temp = new Node();
	temp = head;
	cout << "Text: ";
	while (temp != nullptr) {
		cout << temp->text << " ";
		temp = temp->next;
	}
}


int main()
{
	Node* head1 = nullptr;
	Node* head2 = nullptr;

	char choice;

	do {
		string str;
		cout << "Enter a string: ";
		cin >> str;

		addText(head1, str);
		cout << "Added ";
		display(head1);
		cout << endl << endl;

		deleteText(head1, head2);
		display(head1);
		cout << endl << endl;

		undo(head1, head2);
		display(head1);
		cout << endl << endl;

		redo(head1, head2);
		display(head1);
		cout << endl << endl;


		cout << "Continue? (y/n): ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
}

