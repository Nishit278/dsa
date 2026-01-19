#include <bits/stdc++.h>
#include "Headers/LinkedList.h"
#include "Headers/Stack.h"
using namespace std;


int main()
{
    LinkedList ll;
    ll.append(10);
    ll.append(20);
    ll.append(39);
    ll.viewList();
    ll.insertAtBeginning(99);
    ll.viewList();
    ll.append(69);
    ll.append(234);
    ll.viewList();
    ll.insertAtIndex(29, 1);
    ll.viewList();
    ll.insertAtIndex(49, 8);
    ll.viewList();
    ll.insertAtIndex(79, 3);
    ll.viewList();
    ll.deleteAtHead();
    ll.viewList();
    ll.deleteAtTail();
    ll.viewList();
    ll.deleteAtIndex(2);
    ll.deleteAtIndex(3);
    ll.viewList();
    ll.deleteWithValue(20);
    ll.viewList();
    ll.deleteWithValue(20);
    ll.reverseWithoutRecursion();
    ll.viewList();
    ll.append(99);
    ll.append(2039);
    ll.append(21);
    Node *head = ll.returnHead();
    ll.reverseUsingRecursion(head, NULL);
    ll.viewList();

    Stack st;
    st.push(10);
    st.push(8);
    st.push(9);
    st.push(20);
    st.push(86);
    st.viewStack();
    st.pop();
    st.viewStack();
    cout << st.top() << endl;

    return 0;
}

// !! - g++ main.cpp LinkedList.cpp Stack.cpp -o main  - run this command to compile all files
// !! - g++ main.cpp Implementations/Stack.cpp Implementations/LinkedList.cpp -o main - depending on the location of the files
// !! - ./main to run the executable file in mac and main.exe in windows
