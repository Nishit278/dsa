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

Node* middle(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast != NULL){
		fast = fast->next;
		slow=slow->next;
		if(fast->next==NULL) return slow;
		fast = fast->next;
	}
	return slow;
}

void display(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	Node* head = NULL;
	insert_at_head(head, 1);
	insert_at_head(head, 2);
	insert_at_head(head, 3);
	insert_at_head(head, 4);
	insert_at_head(head, 5);
	insert_at_head(head, 6);
	insert_at_head(head, 7);
	insert_at_head(head, 8);
	display(head);
	auto slow = middle(head);
	display(slow);


	display(head);

}