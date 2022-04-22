#pragma once
#include <iostream>
#include<vector>
#include<algorithm>
#include <assert.h>
using namespace std;
struct Node {
	int data{ };
	Node* next{ };
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}

};

class SinglyLinkedList
{
private:
	Node* head;
	Node* tail;
	int length = 0;
	vector<Node*>DebugData;
	void DebugAddNode(Node* node) {
		DebugData.push_back(node);
	}
	void DebugRemoveNode(Node*node) {
		auto it = find(DebugData.begin(), DebugData.end(),node);
		if (it != DebugData.end()) {
			DebugData.erase(it);
		}
		else
			cout << "Node doesn't exist\n";
	}

public:
	//prevents copy and assign :
	SinglyLinkedList() {
		head = tail = NULL;
	}
	//prevent passing without refrence
	SinglyLinkedList(const SinglyLinkedList&) = delete;
	SinglyLinkedList &operator= (const SinglyLinkedList& list2) = delete;
	void DebugPrintNode(Node*node) {
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void DebugPrintList() {
		for (int i = 0; i < DebugData.size(); i++) {
			DebugPrintNode(DebugData[i]);
		}
	}
	void DataIntegrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		}
		else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1) {
				assert(head==tail);
			}
			else {
				assert(head != tail);
				assert(!tail->next);

			}
		}
		int len = 0;
		for (Node* curr = head; curr;curr=curr->next,len++ ) {
			assert(len<1e4);
		}
		assert(length==len);

		assert(length == (DebugData.size()));
	}
	
	//opertations:
public:
	bool IsSame(SinglyLinkedList& list);
	void Print();
	Node* GetNthFromFront(int index);
	Node* GetNthFromBack(int index);
	void AddNode(Node* node);
	void RemoveNode(Node* node);
	void InsertEnd(int value);
	void InserFront(int value);
	void DeleteFront();
	void DeleteLast();
	void DeleteNthNode(int index);
	~SinglyLinkedList();
};

