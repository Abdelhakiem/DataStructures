#pragma once
struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int data):data(data){}
	void set(Node*next,Node*prev) {
		this->next = next;
		this->prev = prev;
	}
};
class DoublyLinkedList
{


};

