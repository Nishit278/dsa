#include <bits/stdc++.h>
using namespace std;

// Building block
struct node
{
	int data;
	node *link;
};

// Creating a new node
node *newnode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->link = NULL;
	return temp;
}

// Adding a node to the beginning of our linked list
node *addstart(node *head, int data)
{
	if (head == NULL)
		return newnode(data);
	node *temp = newnode(data);
	temp->link = head;
	head = temp;
	return temp;
}
// Adding a node to the end of our linked list
node *append(node *head, int data)
{
	if (head == NULL)
		return newnode(data);
	else
	{
		node *temp = newnode(data);
		node *ptr = head;
		for (; ptr->link != NULL; ptr = ptr->link)
			;
		ptr->link = temp;
	}
	return head;
}

// Adding a node after a point
node *addafter(node *head, int data, int point)
{
	node *temp = newnode(data);
	node *ptr = head;
	for (; ptr->data != point; ptr = ptr->link)
		;
	temp->link = ptr->link;
	ptr->link = temp;
	return head;
}

// Adding a node before a point
node *addbefore(node *head, int data, int point)
{
	if (head->data == point)
		return addstart(head, data);
	node *ptr = head;
	for (; ptr->link->data != point && ptr->link != NULL; ptr = ptr->link)
		;
	node *temp = newnode(data);
	temp->link = ptr->link;
	ptr->link = temp;
	return head;
}

// Delete the first node
node *deletestart(node *head)
{
	if (head == NULL)
		return head;
	node *temp = head;
	head = head->link;
	delete (temp);
	return head;
}

// Delete the last node
node *deletelast(node *head)
{
	if (head == NULL)
		return head;
	if (head->link == NULL)
	{
		node *ptr = head;
		delete (ptr);
		return NULL;
	}
	node *ptr = head;
	for (; ptr->link->link != NULL; ptr = ptr->link)
		;
	ptr->link = NULL;
	return head;
}

// Delete a particular node in list
node *deletenode(node *head, int point)
{
	if (head->data == point)
		return deletestart(head);
	node *ptr = head;
	for (; ptr->link->data != point && ptr->link != NULL; ptr = ptr->link)
		;
	node *ptr2 = ptr->link;
	ptr->link = ptr2->link;
	delete (ptr2);
	return head;
}

// reversing the list
node *reverse(node *head)
{
	node *prev = NULL;
	node *next = NULL;
	node *curr = head;
	while (curr != NULL)
	{
		next = curr->link;
		curr->link = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// sorting the list(mergesort)
node *mergesort(node *head)
{
	return head;
}

// Printing the list
void print(node *head)
{
	node *ptr = head;
	for (; ptr != NULL; ptr = ptr->link)
	{
		cout << ptr->data;
		(ptr->link != NULL) ? cout << " -> " : cout << "  ";
	}
	cout << "\n";
}

int main()
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	char cont = 'y';
	node *head = NULL;
	int data, point, choice;
	while (cont == 'y')
	{

		cout << "\n**LINKED LIST**\n";
		cout << "0.Print the linked list\n";
		cout << "1.Add at the beginning\n";
		cout << "2.Add at the ending\n";
		cout << "3.Add before a point\n";
		cout << "4.Add after a point\n";
		cout << "5.Delete at the beginning\n";
		cout << "6.Delete at the end\n";
		cout << "7.Delete at a point\n";
		cout << "8.Reversing the list\n";
		cout << "9.Sorting(Merge Sort) the list\n";
		// cout << "10.\n";
		cout << "Choose from these commands ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			print(head);
			break;
		case 1:
			cout << "\nEnter the value ";
			cin >> data;
			head = addstart(head, data);
			break;
		case 2:
			cout << "\nEnter the value ";
			cin >> data;
			head = append(head, data);
			break;
		case 3:
			cout << "\nEnter the value ";
			cin >> data;
			cout << "\nEnter the point ";
			cin >> point;
			head = addbefore(head, data, point);
			break;
		case 4:
			cout << "\nEnter the value ";
			cin >> data;
			cout << "\nEnter the point ";
			cin >> point;
			head = addafter(head, data, point);
			break;
		case 5:
			head = deletestart(head);
			break;
		case 6:
			head = deletelast(head);
			break;
		case 7:
			cout << "\nEnter the point ";
			cin >> point;
			head = deletenode(head, point);
			break;
		case 8:
			head = reverse(head);
			break;
		case 9:
			head = mergesort(head);
			break;
		// case 10:

		// 	break;
		default:
			cout << "\nUnrecognised command\n";
			break;
		}
		cout << "Do you want to continue?(y/n) ";
		cin >> cont;
	}

	return 0;
}
