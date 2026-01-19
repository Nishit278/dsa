#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int x): data(x), next(NULL){}
};

void insert_at_head(Node* &head, int data){
	if(head==NULL){
		head = new Node(data);
		return;
	}
	Node* n = new Node(data);
	n->next = head;
	head = n;
}

void insert(Node* &head, int data, int pos){
	if(pos==0){
		insert_at_head(head, data);
		return;
	}
	Node* ptr = new Node(data);
	Node* temp = head;
	pos = pos-1;
	while(pos--){
		temp = temp -> next;
	}
	ptr->next = temp->next;
	temp->next = ptr;

}

Node* rec_reverse(Node* head){
	if (head == NULL or head->next==NULL){
		return head;
	}
	Node* sHead = rec_reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return sHead;
}

void display(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout << temp->data << "->";
		temp = temp->next;
	}
}

int main(){
	Node* head = NULL;
	insert_at_head(head, 6);
	insert_at_head(head, 9);
	insert_at_head(head, 2);
	display(head);
	cout << endl;
	head = rec_reverse(head);
	display(head);
}