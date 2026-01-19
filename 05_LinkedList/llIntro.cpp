#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
    node(int x) : data(x), next(NULL) {} //constructor which assigns values to the first node 
};

void insertAtPos(node* &head, int val, int pos){
    node *n = new node(val);
    if(pos == 0 ){
        n->next = head;
        head = n;
        return;
    }
    node *temp = head;
    int it = 0;
    while (it<pos-1){
        // cout << temp->data << endl;
        temp = temp->next;
        it++;
    }
    n->next = temp->next;
    temp->next = n;
}

void insertBack(node* &head , int val){
    node *n = new node(val);
    // new node *n(val); // not correct syntactically 
    if (head == NULL)
    {
        head = n;
        return; // or we can call insert at front here 
    }
    node *temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
        // cout << temp << " " << temp->next << endl;
    }
    temp->next = n;
   
}
void insertFront(node* &head, int val){
    
    node *n = new node(val);
    n->next = head;
    head = n;
}

void deleteNode(node* head, int pos){
    if(pos == 0){
        head = head->next;
        return;
    }
    node *temp = head;
    int it = 0;
    while(it<pos-1){
        temp = temp->next;
        it++;
    }
    temp->next = temp->next->next;

}

bool search(node* head, int key){
    node *temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void display(node* head){
    node *temp = head;
    while (temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertBack(head,2);
    insertBack(head,6);
    insertBack(head,1);
    // insertFront(head, 32);
    // insertFront(head, 12);
    insertBack(head, 2);
    insertBack(head,6);
    display(head);
    insertAtPos(head, 8, 3);
    display(head);
    deleteNode(head, 3);
    display(head);
    cout << search(head, 8) << endl;

    return 0;
}