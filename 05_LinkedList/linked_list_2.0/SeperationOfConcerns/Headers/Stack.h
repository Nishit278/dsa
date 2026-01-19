#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
private:
    LinkedList ll;

public:
    int top();
    void pop();
    void push(int val);
    bool isEmpty();
    void viewStack();
};

#endif // STACK_H