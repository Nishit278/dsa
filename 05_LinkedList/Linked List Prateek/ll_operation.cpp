class List;

class Node{
	int data;
	Node* next;

public:
	Node(int x): data(x), next(nullptr) {}
	friend class List;
};	
class List{
	Node* head;
	Node* tail;

public:
	List(): head(NULL), tail(NULL){}

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
};
