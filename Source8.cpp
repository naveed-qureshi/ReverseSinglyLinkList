#include <iostream>
using namespace std;
struct  Node
{
	int data;
	Node* next;
};

class LinkList {
	Node* head;

public:
	LinkList() {
		head = NULL;
	}
	void reverse() {
		if (head == NULL)
			return;
		else if (head->next == NULL)
			return;
		else if (head->next->next == NULL) {
			Node* temp = head->next;
			temp->next = head;
			head->next = NULL;
			head = temp;
			return;
		}
		else {
			Node* temp1 = head;
			int data = head->data;
			Node* temp2 = temp1->next;
			Node* temp3 = temp2->next;
			Node* temp = nullptr;
			while (temp3->next!=nullptr) {
				temp2->next = temp1;
				temp1 = temp2;
				temp2 = temp3;
				temp3 = temp3->next;
			}
			temp2->next = temp1;
			temp3->next = temp2;
			head->next = nullptr;
			head = temp3;
			return;

		}
	}

	void add(int a) {
		if (head == nullptr) {
			head = new Node();
			head->data = a;
		}
		else {
			Node* temp = head;
			while (temp->next)
			{
				temp=temp->next;
			}
			temp->next = new Node();
			temp->next->data = a;
		}
	}
	void display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	LinkList l;
	l.add(5);
	l.add(6);
	l.add(1);
	l.add(2);
	l.display();
	l.reverse();
	l.display();
}