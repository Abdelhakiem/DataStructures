

#ifndef DATASTRUCTURE_CLION_LINKEDSTACK_H
#define DATASTRUCTURE_CLION_LINKEDSTACK_H

#pragma once
//Implemeting stack using single linked list.
#include<assert.h>
#include <iostream>
using namespace std;
struct Node
{
    int value {};
    Node* next {};
    Node(int value) : value(value) { next = nullptr; }
    Node() { value = 0; next = nullptr; }
};
class LinkedStack
{
private:
    Node* top =nullptr;
public:

    void Push(int value) {
        Node* temp = new Node(value);
        temp->next = top;
        top = temp;
    }
    int Pop() {
        assert(!IsEmpty());
        Node* temp = top;
        top = top->next;
        int value = temp->value;
        delete temp;
        return value;
    }
    int Peek() {
        assert(!IsEmpty());
        return top->value;
    }
    bool IsFull() {
        return false;
    }
    bool IsEmpty() {
        return !top;
    }
    void Display() {
        for (Node*temp = top; temp; temp=temp->next)
        {
            cout << temp->value<<" ";

        }
    }
    ~LinkedStack() {

        while (!IsEmpty()) {
            Pop();
        }
    }

};



#endif //DATASTRUCTURE_CLION_LINKEDSTACK_H
