#pragma once
#include <iostream>
#include<vector>
#include<algorithm>
#include <assert.h>
using namespace std;
struct Node {
	int data{ };
	Node* next{};
	Node(int data) : data(data) {
		next = NULL;
	}

	~Node() {
	}
};

class SinglyLinkedList
{
private:
	Node* head;
	Node* tail;
	int length = 0;
	//storing nodes in vector to visualize and track the nodes.
	vector<Node*>DebugData;
	void DebugAddNode(Node* node);
	void DebugRemoveNode(Node* node);
	void AddNode(Node* node);
	void RemoveNode(Node* node);

	void DebugPrintNode(Node* node);
	void DebugPrintList();
	void DataIntegrity();
	//prevents copy and assign :
	//prevent passing without refrence
public:
	SinglyLinkedList() {
		head = tail = NULL;
	}
	SinglyLinkedList(const SinglyLinkedList&) = delete;
	SinglyLinkedList& operator= (const SinglyLinkedList& list2) = delete;
	//opertations:

	bool IsSame(SinglyLinkedList& list);
	void Print();
	Node* GetNthFromFront(int index);
	Node* GetNthFromBack(int index);
	void InsertEnd(int value);
	void InserFront(int value);
	void DeleteFront();
	void DeleteLast();
	void DeleteNthNode(int index);
	~SinglyLinkedList();


};


