#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
    node *prev;
    node(int x): val(x), next(NULL), prev(NULL) {};
};

node* insertAtFront(node* head, int val){
    node *ptr = new node(val);
    ptr->next = head;
    if(head){
        head->prev = ptr;
    }
    head = ptr;
    return head;
}

node* insertAtTail(node* head, int val){
    if(!head){
        head = insertAtFront(head, val);
        return head;
    }
    node *ptr = new node(val);
    node *temp = head;
    for (; temp->next != NULL; temp=temp->next){}
    temp->next = ptr;
    ptr->prev = temp;
    return head;
}

node *deleteAtPos(node* head, int pos){
    auto temp = head;
    if(pos==1){
        head = head->next;
        head->prev = NULL;
        delete (temp);
        return head;
    }
    int it = 1;
    while (temp !=NULL && it != pos)
    {
        temp = temp->next;
        it++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
    temp->next->prev = temp->prev;
    }
    delete (temp);
    return head;
}

void display(node* head){
    auto ptr = head;
    for (; ptr!= NULL;ptr=ptr->next){
        cout << ptr->val;
        cout << ((ptr->next == NULL) ? "" : "->");
    }
    cout << endl;
}

int main(){
    node *head = NULL;
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 5);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 8);
    head = insertAtFront(head, 9);
    // head = deleteAtPos(head, 2);
    // head = deleteAtPos(head, 2);
    // head = deleteAtPos(head, 2);
    display(head);
    return 0;
}