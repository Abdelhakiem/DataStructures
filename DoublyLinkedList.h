#pragma once
#include <iostream>
#include<vector>
#include<assert.h>
using namespace std;
//The major diffrence between singly and doubly linked list is that
// in doubly linked list we can iterate forward and backward.

struct Node
{
	int data;
	Node* next{};
	Node* prev{};
	Node(int data):data(data),next(NULL),prev(NULL){}
	void SetData(int data){
		this->data = data;
	}
	void SetPrevious(Node* prev) {
		this->prev = prev;
	}
	void SetNext(Node* next) {
		this->next = next;
	}
};
class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
	int length=0;
	vector<Node*>DebugData;
	
	//private operations: 
	
	void DebugPrintNode(Node*node) {
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		if (node->prev != nullptr)
			cout << node->prev->data << " <- ";			
		else cout << "X" << " <- ";
			
		cout <<" [ " << node->data << " ] ";
		if(node->next != nullptr)
			cout  << " -> " << node->next->data;
		else cout << " -> " << "X";


		if (node == head)
			cout << " : head\n";
		else if (node == tail)
			cout << " : tail\n";
		else
			cout << "\n";
	}
	void DebugPrintList() {
			for (int i = 0; i < DebugData.size(); i++) {
				DebugPrintNode(DebugData[i]);
			}
		}
	void DebugAddNode(Node* node);
	void DebugRemoveNode(Node* node);
	void AddNode(Node* node);
	void RemoveNode(Node* node);
	//Pre: user must enter nodes in the right order
	void LinkTwoNodes(Node* node1, Node* node2) {
		if(node1)
			node1->next = node2;
		if(node2)
			node2->prev = node1;
	}
	void DataIntegrity();
public:
	DoublyLinkedList() {
		head = tail = NULL;
	}
	DoublyLinkedList(const DoublyLinkedList&) = delete;
	DoublyLinkedList& operator= (const DoublyLinkedList& list2) = delete;
	//operations for the user:
	//displaying methods:
	 void PrintForward();
	 void PrintBackward();
	 //insertion methods:
     void InsertFront(int value);
	 void InsertBefore(int value, Node* node_after);
	 void InsertSorted(int value);
	 void InserEnd(int value);
	 //deletion methods
	 void DeleteFront();
	 void DeleteEnd();
	
	 //destructor : displays current nodes and freeing allocated memory
	~DoublyLinkedList() {
		DebugPrintList();
		 for (Node* curr = head; curr;) {
			 curr = head->next;
			 RemoveNode(head);
			 head = curr;
		 }
	 }
	
	
};

