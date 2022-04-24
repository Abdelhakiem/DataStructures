#include "SinglyLinkedList.h"




void SinglyLinkedList::DataIntegrity() {
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
		assert(len < 1e4);
	}
	assert(length == len);

	assert(length == (DebugData.size()));
}


bool SinglyLinkedList::IsSame(SinglyLinkedList& list) {
		Node* node1 = head, * node2 = list.head;
		while (node1 && node2) {
			if (node1->data != node2->data) {
				return false;
			}
			node1 = node1->next;
			node2 = node2->next;
		}
		//to make sure both ended
		return (!node1 && !node2);
	}

	void SinglyLinkedList::Print() {
		for (Node* curr = head; curr; curr = curr->next) {
			cout << curr->data << " ";
		}
		cout << endl;
	}
	//one based indexing
	Node* SinglyLinkedList::GetNthFromFront(int index) {
		int cnt = 0;
		for (Node* curr = head; curr; curr = curr->next) {
			if (++cnt == index) {
				return curr;
			}
		}
		return nullptr;

	}

	Node* SinglyLinkedList::GetNthFromBack(int index) {
		index = length + 1 - index;
		return GetNthFromFront(index);

	}

	void SinglyLinkedList::DebugAddNode(Node* node) {
		DebugData.push_back(node);
	}

	void SinglyLinkedList::DebugRemoveNode(Node* node)
	{
		auto it = find(DebugData.begin(), DebugData.end(), node);
		if (it != DebugData.end()) {
			DebugData.erase(it);
		}
		else
			cout << "Node doesn't exist\n";
		//cout << "DebugRemoveNode" << endl;
	}

	void SinglyLinkedList::AddNode(Node* node) {
		DebugAddNode(node);
		length++;
		//cout << "added successfully" << endl;
	}

	void SinglyLinkedList::RemoveNode(Node* node) {
		length--;
		DebugRemoveNode(node);
		cout << "remove node" << endl;
		delete node;
		cout << " node removed" << endl;
	}

	void SinglyLinkedList::DebugPrintNode(Node* node) {
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

	void SinglyLinkedList::DebugPrintList() {
		for (int i = 0; i < DebugData.size(); i++) {
			DebugPrintNode(DebugData[i]);
		}
	}

	void SinglyLinkedList::InsertEnd(int value) {
		Node* temp = new Node(value);
		AddNode(temp);
		if (head == nullptr) {
			head = tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
		//To make sure that the operation attempted successfully:
		DataIntegrity();
	}

	void SinglyLinkedList::InserFront(int value) {
		Node* temp = new Node(value);

		AddNode(temp);

		if (!head) {
			head = tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}

		DebugPrintList();
		//To make sure that the operation attempted successfully:
		DataIntegrity();
	}

	void SinglyLinkedList::DeleteFront() {
		assert(length);

		if (head) {
			Node* temp = head->next;
			RemoveNode(head);
			head = temp;
		}
		if (!head)
			tail = nullptr;
		DataIntegrity();
	}

	void SinglyLinkedList::DeleteLast()
	{
		if (length <= 1) {
			DeleteFront();
			return;
		}
		Node* new_tail = GetNthFromFront(length - 1);
		new_tail->next = nullptr;
		RemoveNode(tail);
		tail = new_tail;
		DataIntegrity();
	}

	void SinglyLinkedList::DeleteNthNode(int index) {
		if (index == 1) {
			DeleteFront();
			return;
		}
		else if (index < 1 || index < length) {
			cout << "There is no node with such an index\n";
			return;
		}
		Node* prev = GetNthFromFront(index - 1);
		Node* curr = prev->next;

		prev->next = curr->next;
		RemoveNode(curr);
		DataIntegrity();
	}
	SinglyLinkedList::~SinglyLinkedList() {
		for (Node* curr = head; curr;) {
			cout << "looping" << endl;
			curr = head->next;
			//RemoveNode(head);
			delete head;
			head = curr;
		}


	}




