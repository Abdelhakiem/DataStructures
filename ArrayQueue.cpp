//
// Created by INTEL on 4/28/2022.
//

#include "ArrayQueue.h"

void ArrayQueue::Display() {
    int curr=front;
    for(int i=0;i<size;i++){
        cout<<pque[(curr++) % MAX_SIZE ]<<" ";
    }
    cout<<endl;
}

int ArrayQueue::Dequeue() {
    if(!IsEmpty()){
        size--;
        front= (front+1)%MAX_SIZE;
    }
    Front();
}

void ArrayQueue::Enqueue(int value) {
    assert(!IsFull());
    size++;
    rear=(rear+1)%MAX_SIZE;
    pque[rear]=value;
}

ArrayQueue::ArrayQueue(int max_size) {
    size=0;
    MAX_SIZE=max_size;
    pque=new int[max_size];
    front=0;
    rear=-1;
}

int ArrayQueue::Front(){
    assert(!IsEmpty());
    return pque[front];
}
