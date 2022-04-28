//
// Created by INTEL on 4/27/2022.
//

#ifndef DATASTRUCTURE_CLION_ARRAYSTACK_H
#define DATASTRUCTURE_CLION_ARRAYSTACK_H

#include <iostream>
#include<assert.h>
#define STACK_SIZE 1e3
using namespace std;
class ArrayStack
{
private:
    int length;
    int* arr;
    //top is an index to the last entered entry
    int top;
public:
    ArrayStack(int lenght):length(lenght) {
        arr = new int[lenght];
        top = -1;
    }
    ArrayStack():ArrayStack(STACK_SIZE) {}

    void Push(int value);
    int Pop();
    void Clear() {

    }
    int Peek();
    bool IsFull();
    bool IsEmpty() {
        return false;
    }
    void Display();
    ~ArrayStack() {
        delete []arr;
    }
};


#endif //DATASTRUCTURE_CLION_ARRAYSTACK_H
