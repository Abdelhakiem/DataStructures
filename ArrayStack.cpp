
#include "ArrayStack.h"

void ArrayStack::Push(int value)
{
    assert(!IsFull());
    arr[++top] = value;
}
int ArrayStack::Pop()
{
    assert(!IsEmpty());
    return arr[top--];
}
int ArrayStack::Peek()
{
    assert(!IsEmpty());
    return arr[top];
}

bool ArrayStack::IsFull()
{
    return ((top + 1) == length);
}

void ArrayStack::Display()
{
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}