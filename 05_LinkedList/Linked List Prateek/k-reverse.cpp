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

Node* k_reverse(Node* head, int k){
	
        auto ctr = head;
        for(int i = 0; i < k; i++){
            if(ctr == nullptr) return head;
            ctr = ctr->next;
        }
        auto curr = head;
        Node* prev = nullptr;
        for(int i = 0; i < k; i++){
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head->next = k_reverse(curr, k);
        return prev;
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

	head = k_reverse(head, 3);
	display(head);

}