#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node();
    Node(int value);
    Node(int value, Node *next);
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList();
    Node *returnHead();
    void viewList();
    void append(int value);
    void insertAtBeginning(int value);
    void insertAtIndex(int value, int index);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtIndex(int index);
    void deleteWithValue(int value);
    void reverseWithoutRecursion();
    void reverseUsingRecursion(Node *curr, Node *prev);
};

#endif // LINKEDLIST_H