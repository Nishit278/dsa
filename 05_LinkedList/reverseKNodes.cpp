#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x): val(x), next(NULL) {}
};
void display (Node* head){
    auto ptr = head;
    for (; ptr!= NULL;ptr=ptr->next){
        cout << ptr->val;
        cout << ((ptr->next == NULL) ? "" : "->");
    }
    cout << endl;
}
Node* addBack(Node* head, int val){
    Node *temp = new Node(val);
    Node *ptr = head;
    Node *headCpy = head;
    // cout << ptr << endl;
    if (head == NULL)
    {
        return temp;
    }
    while(ptr->next!= NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    return headCpy;
}

Node* reverse(Node* head, int left, int right){
        Node* temp = new Node(0);
        temp->next = head;
        auto front = temp;
        int it = 0;
        while(it<left){
            front = front->next;
            it++;
        }
        auto workPtr = front->next;
        while (left < right-1)
        {
            auto curr = workPtr->next;
            workPtr->next = curr->next;
            curr->next= front->next;
            front->next = curr;
            left++;
        }
        display(temp->next);
        return temp->next;
    }
    Node* reverseKGroup(Node* head, int k) {
        auto temp = head;
        int count=1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        cout << count << endl;
        int it = count / k;
        int left = 0;
        int right = left + k;
        int i = 1;
        while(i<=it){
            cout << left << " " << right << endl;
            head = reverse(head, left, right);
            left += k;
            right += k;
            i++;
        }
        return head;
    }

int main(){
    Node *head = NULL;
    head = addBack(head, 1);
    head = addBack(head, 2);
    head = addBack(head, 3);
    head = addBack(head, 4);
    head = addBack(head, 5);
    display(head);
    head = reverseKGroup(head, 3);
    display(head);
    return 0;
}