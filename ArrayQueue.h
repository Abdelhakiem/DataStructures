/*
Queue data structure based on Array (Circular implementation)
*/

#ifndef DATASTRUCTURESCONITUE_ARRAYQUEUE_H
#define DATASTRUCTURESCONITUE_ARRAYQUEUE_H
#include <iostream>
#include <assert.h>

using namespace std;
class ArrayQueue {
private:
     int* pque;
     int size;
     int front;
     int rear;
     int MAX_SIZE=(int)1e3;
public:
    ArrayQueue(): ArrayQueue(MAX_SIZE){
    }
    ArrayQueue(int max_size);
    ~ArrayQueue(){
        delete pque;
    }

    //enqeue(value) : add in the end of the queue:
    void Enqueue(int value);


    //dequeue(): delete from the front
    int Dequeue();


    //dispalying Current elements in the queue
    void Display();
    //Clear:
    void Clear(){
        size=front=0,rear=-1;
    }

    //int front(): returns the front of the queue;
    int Front();

    //IsEmpty()
    bool IsEmpty(){
        return !size;
    }
    //IsFull()
    bool IsFull(){
        return size==MAX_SIZE;
    }
    //int size(): return the size of the queue;
    int Size(){
        return size;
    }
};


#endif //DATASTRUCTURESCONITUE_ARRAYQUEUE_H
