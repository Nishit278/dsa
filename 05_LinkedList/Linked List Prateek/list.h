#include <iostream>
using namespace std;

class List;
	
class Node{
	int data;
	
public:
	Node* next;

	Node(int x): data(x), next(nullptr){}

	int getData(){
		return data;
	}
	friend class List;
	~Node(){
		if(next!=NULL) delete next;
		cout << "Deleting Node with data: " << data << endl;
	}
};	
class List{
	Node* head;
	Node* tail;

public:
	List(): head(NULL), tail(NULL){}
	Node* begin(){
		return head;
	}

	void push_front_tail(int data){ //using tail
		if(head == NULL){
			Node* ptr = new Node(data);
			head = tail = ptr;
		} else {
			Node* ptr = new Node(data);
			ptr->next = head; // (*ptr).next = head, (*ptr) is the object  
			head = ptr;
		}
	}
	void push_front(int data){
		if(head == NULL){
			Node* n = new Node(data);
			head = n;
		} else {
			Node* n = new Node(data);
			n->next = head;
			head = n;
		}
	}
	void push_back_tail(int key){
		if(head == NULL){
			Node* n = new Node(key);
			head = tail = n;
		} else {
			Node* n = new Node(key);
			tail->next = n;
			tail = n;
		}
	}
	void push_back(int key){
		if(head == NULL){
			Node* ptr = new Node(key);
			head = ptr;
		}
		else {
			Node* n = new Node(key);
			Node* ptr = head;
			while(ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr-> next = n;
			ptr = n;
		}
	}
	void insert(int data, int pos){
		if(pos == 0){
			push_front_tail(data);
			return;
		}
		Node* n = new Node(data);
		Node* temp = head;
		while(--pos){
			temp = temp->next;
		}
		n->next = temp->next;
		temp->next = n;
	}

	void pop_front(){
		if(head == NULL){
			return;
		}
		Node* temp = head; // store a copy of head in temp
		head = head->next; // move head to the next element
		temp->next = NULL; // make temp->next=NULL because it is still pointing to the next element, and if we delete it, the whole linked list will get deleted
		delete temp; // finally delete temp
	}
	void pop_back(){
		if(head==NULL){
			return;
		}
		
		Node* temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		Node* n = temp->next;
		temp->next = n->next;
		n->next = NULL;
		delete(n);
	}

	Node* remove(int pos){
		if(head == NULL)
			return head;
		if(pos==0){
			pop_front();
			return head;
		} else {
			Node* temp = head;
			pos-=1;
			while(pos--){
				temp=temp->next;
			}
			if(temp->next->next == NULL) pop_back();
			else{
				Node* n = temp->next;
				temp->next = n->next;
				n->next = NULL;
				delete(n);
			}

		}
		return head;
	}

	Node* reverse(){
		if(head == NULL) return head;
		Node* curr = head;
		Node* prev = NULL;
		while(curr != NULL){
			Node* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		head = prev; //other wise head = first element and head->next = NULL
		return prev;
	}

	~List(){
		if(head!=NULL){
			delete head;
			head = NULL;
		}
	}
};


/***
 * *************************DELETION USING DESTRUCTOR**********************
 * When the main function ends, it tries to destroy all its local variables
 * when it does so, the destructor of the List class is called and 
 * it then further calls the destructor of the Node class
 * The "delete" keyword works recursively
 * when we say delete head in ~List()
 * it calls the destructor ~Node()
 * it checks if the next element is NULL or not, if not NULL, it calls
 * delete next
 * which recursively calls the remaining list
 * so if we have a list 3->2->4->9->1->6->7
 * deletion will start from 7 and 3 will be deleted last
 ***/