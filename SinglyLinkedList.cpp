#include "SinglyLinkedList.h"

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
	GetNthFromFront(index);
}

void SinglyLinkedList::AddNode(Node* node) {
	DebugAddNode(node);
	length++;
}

void SinglyLinkedList::RemoveNode(Node* node) {
	length--;
	DebugRemoveNode(node);
	delete node;
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

}

void SinglyLinkedList::DeleteFront() {
	assert(length);
	
	if(head){
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
	Node* new_tail =GetNthFromFront(length-1) ;
	new_tail->next = nullptr;
	delete tail;
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

		curr = head->next;
		delete head;
		head = curr;
	}

}
