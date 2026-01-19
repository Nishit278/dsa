#include "../Headers/LinkedList.h"
using namespace std;

Node::Node() : data(0), next(NULL) {}
Node::Node(int value) : data(value), next(NULL) {}
Node::Node(int value, Node *next) : data(value), next(next) {}

LinkedList::LinkedList() : head(nullptr) {}

Node *LinkedList::returnHead() { return head; }

void LinkedList::viewList()
{
    for (Node *temp = head; temp != nullptr; temp = temp->next)
    {
        cout << temp->data << "->";
    }
    cout << endl;
}

// !--------------------------------INSERTION IN LINKED LIST ------------------------------------------
// * Append at the end of the LinkedList
void LinkedList::append(int value)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// * Append at the beginning of the LinkedList
void LinkedList::insertAtBeginning(int value)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    newNode->next = head; // Point the next of the newNode to head
    head = newNode;       // Update the head
}
// * Append at a particular index of the LinkedList
void LinkedList::insertAtIndex(int value, int index)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    if (index == 0)
    {
        insertAtBeginning(value);
        return;
    }
    Node *temp = head;
    int currInd = 0;
    while (currInd < index - 1 && temp != nullptr)
    {
        temp = temp->next;
        currInd++;
    }
    if (temp == nullptr)
    {
        cout << "Invalid index provided!" << endl;
        delete newNode; // clean the memory
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

//  !--------------------------------DELETION IN LINKED LIST ------------------------------------------
// ! Delete the first element of the LL
void LinkedList::deleteAtHead()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
// ! Delete the last element of the LL
void LinkedList::deleteAtTail()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    // By the end of this loop, temp is at the second-last element of the list
    Node *nodeToBeDeleted = temp->next; // the last node
    temp->next = nodeToBeDeleted->next; // or we can manually set to nullptr it's the same
    delete nodeToBeDeleted;
}
// ! Delete at specific index
void LinkedList::deleteAtIndex(int index)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *curr = head;
    int currInd = 0;
    while (currInd < index - 1 && curr != nullptr)
    {
        curr = curr->next;
        currInd++;
    }

    if (curr == nullptr)
    {
        cout << "Index out of bounds!" << endl;
        return;
    }

    // curr is the element before the node we want to delete
    Node *nodeToBeDeleted = curr->next;
    curr->next = curr->next->next;
    delete nodeToBeDeleted;
}

// ! Delete a node with a given value
void LinkedList::deleteWithValue(int value)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *itr = head;
    while (itr->next != nullptr)
    {
        if (itr->next->data == value)
        {
            Node *nodeToBeDeleted = itr->next;
            itr->next = itr->next->next;
            delete nodeToBeDeleted;
            return;
        }
        itr = itr->next;
    }

    cout << "Element not found!" << endl;
    return;
}

// ! Reverse a LinkedList without recursion
void LinkedList::reverseWithoutRecursion()
{
    if (head == nullptr)
    {
        cout << "Empty list!" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        cout << "Only one element in the list" << endl;
        return;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
// ! Reverse LL using recursion
void LinkedList::reverseUsingRecursion(Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *temp = curr->next;
    curr->next = prev;
    reverseUsingRecursion(temp, curr);
}