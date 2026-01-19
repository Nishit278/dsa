#include <bits/stdc++.h>
#include "list.h"

using namespace std;

void display(Node* head){
	Node* temp = head;
	while(temp!= NULL){
		cout << temp->getData() << "->";
		temp = temp->next;

	}
	cout << "\n";
}
bool search(Node* head, int key){
	Node* temp = head;
	while(temp!=NULL){
		if(temp->getData() == key){
			return true;
		} else {
			temp = temp->next;
		}
	}
	return false;
}

bool searchRecursive(Node* head, int key){
	Node* temp = head;
	if(temp == NULL){
		return false;
	}
	if(temp->getData() == key){
		return true;
	}
	else {
		return searchRecursive(temp->next, key);
	}
}

int main(){
	List l; // l is a static object, when the main function will end, destructor will be called automatically.
	l.push_front(2);
	l.push_front(5);
	l.push_back(10);
	l.push_front(4);
	l.push_front(9);
	l.push_back(11);
	l.insert(21, 4);
	l.insert(7, 0);
	l.insert(69, 1);
	// l.pop_front();
	auto head = l.remove(0); // head needs to be updated since the first element is deleted
	display(head);
	// cout << search(head, 69)<< endl;
	// cout << search(head, 59)<< endl;
	// cout << search(head, 2) << endl;
	// cout << search(head, 8) << endl;
	// cout << searchRecursive(head, 21) << endl;
	// l.remove(4);
	// cout << head->getData() << endl; // we don't need to redefine head until we are deleting it, as long as an element other than the head is deleted we don't need to do anything.
	display(head);
	head =l.reverse();
	display(head);

	int k = 4;
	while(k--){
		cout << k << " ";
	}
	cout << endl;
	 k = 4;

	for(int i=0;i<k;i++){
		cout << i << " ";
	}
	cout << endl;
	return 0;

}