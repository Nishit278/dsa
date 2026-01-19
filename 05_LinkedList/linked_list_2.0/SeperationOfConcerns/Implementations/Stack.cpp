#include "../Headers/Stack.h"
#include <stdexcept>

int Stack::top() {
    Node *head = ll.returnHead();
    if (head == nullptr) {
        throw runtime_error("Stack is empty");
    }
    return head->data;
}

void Stack::pop() { ll.deleteAtHead(); }

void Stack::push(int val) { ll.insertAtBeginning(val); }

bool Stack::isEmpty() { return ll.returnHead() == NULL; }

void Stack::viewStack() { ll.viewList(); }