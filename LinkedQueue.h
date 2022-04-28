//
// Implementing queue based on linked list
//

#ifndef DATASTRUCTURESCONITUE_LINKEDQUEUE_H
#define DATASTRUCTURESCONITUE_LINKEDQUEUE_H
#include <iostream>
#include <assert.h>

using namespace std;
struct Node{
    int value;
    Node*next;
    Node(): Node(0){

    }
    Node(int value){
        next= nullptr,this->value=value;
    }

};

class LinkedQueue {
private:
    Node*front{};
    Node*rear{};
    int size;
public:

    LinkedQueue(){
        front=rear= nullptr;
        size=0;
    }
    ~LinkedQueue(){
        Clear();
    }

    //enqeue(value) : add in the end of the queue:
    void Enqueue(int value){
        Node*temp=new Node(value);
        size++;
        if(IsEmpty()){
            front=rear=temp;
        }
        else{
            rear->next=temp;
             rear=rear->next;
        }
    }


    //dequeue(): delete from the front
    int Dequeue(){
        assert(!IsEmpty());
        size--;
        int value=front->value  ;

        Node*temp=front;
        front=front->next;
        delete temp;

        return value;
    }


    //dispalying Current elements in the queue
    void Display(){
        for (Node*temp = front; temp ; temp=temp->next) {
            cout<<temp->value<<" ";
        }
        cout<<endl;
    }
    //Clear:
    void Clear(){
        while (front) {
            Node *temp = front->next;
            delete front;
            front = temp;
        }
    }

    //int front(): returns the front of the queue;
    int Front(){
        assert(!IsEmpty());
        return front->value;
    }

    //IsEmpty()
    bool IsEmpty(){
        return front== nullptr;
    }
    //IsFull()
    bool IsFull(){
        return false;
    }
    //int size(): return the size of the queue;
    int Size(){
        return size;
    }


};


#endif //DATASTRUCTURESCONITUE_LINKEDQUEUE_H
