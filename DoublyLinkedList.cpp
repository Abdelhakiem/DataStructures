#include "DoublyLinkedList.h"


void DoublyLinkedList::DebugAddNode(Node* node) {
	DebugData.push_back(node);
}


void DoublyLinkedList::DebugRemoveNode(Node* node) {
	auto it = find(DebugData.begin(), DebugData.end(), node);
	if (it != DebugData.end()) {
		DebugData.erase(it);
	}
	else
		cout << "Node doesn't exist\n";
}



void DoublyLinkedList::DataIntegrity() {
	if (length == 0) {
		assert(head == nullptr);
		assert(tail == nullptr);
	}
	else {
		assert(head != nullptr);
		assert(tail != nullptr);
		if (length == 1) {
			assert(head == tail);
		}
		else {
			assert(head != tail);
			assert(!tail->next);

		}
	}
	int len = 0;
	for (Node* curr = head; curr; curr = curr->next, len++) {
		//Make sure of no cycles
		assert(len < 1e4);
	}
	assert(length == len);

	assert(length == (DebugData.size()));
}

void DoublyLinkedList::PrintForward() {
	for (Node* curr = head; curr; curr = curr->next) {
		cout << curr->data << " ";
	}
	cout << endl;
}

void DoublyLinkedList::PrintBackward() {
	for (Node* curr = tail; curr; curr = curr->prev) {
		cout << curr->data << " ";
	}
	cout << endl;
}
void DoublyLinkedList::AddNode(Node* node)
{
	length++;
	DebugAddNode(node);
}

void DoublyLinkedList::RemoveNode(Node* node) {
	length--;
	DebugRemoveNode(node);
	delete node;
}
void DoublyLinkedList::InsertFront(int value) {
	Node* temp = new Node(value);
	AddNode(temp);
	if (!head) {
		head = tail = temp;
	}
	else {
		LinkTwoNodes(temp, head);
		head = head->prev;
	}
	DataIntegrity();
}

void DoublyLinkedList::InserEnd(int value) {
	Node* temp = new Node(value);
	AddNode(temp);
	if (!head) {
		head = tail = temp;
	}
	else {
		LinkTwoNodes(tail, temp);
		tail = tail->next;
	}
	DataIntegrity();
}

void DoublyLinkedList::DeleteFront()
{
	if (!head) {
		return;
	}
	Node* temp = head->next;
	RemoveNode(head);
	head = temp;
	if (head) {
		head->prev = nullptr;
	}
	else if (length == 0) {
		tail = nullptr;
	}
	DataIntegrity();

}

void DoublyLinkedList::DeleteEnd() {
	if (!head) {
		return;
	}
	Node* temp = tail->prev;
	RemoveNode(tail);
	tail = temp;
	if (tail) {
		tail->next = NULL;
	}
	else if (length == 0) {
		head = nullptr;
	}
	DataIntegrity();

}


void DoublyLinkedList::InsertBefore(int value, Node* node_after) {
	Node* middle = new Node(value);
	AddNode(middle);
	Node* node_before = node_after->prev;
	LinkTwoNodes(middle, node_after);
	LinkTwoNodes(node_before, middle);
	DataIntegrity();
}

void DoublyLinkedList::InsertSorted(int value) {
	if (!head || head->data >= value) {
		InsertFront(value);
	}
	else if (value >= tail->data) {
		InserEnd(value);
	}
	else {
		for (Node* curr = head; curr; curr = curr->next) {
			if (value <= curr->data) {
			InsertBefore(value, curr);
				break;
			}
		}

	}
}
