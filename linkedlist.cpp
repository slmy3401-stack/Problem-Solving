#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
struct node
{
	int data;
	node* next;
	node (int data) : data(data) {}
};
class Linkedlist {
private:
	node* head{};
	node* tail{};
	int counter = 0;
public:
	void insert_end(int value) {
		node* newnode = new node(value);

		if (!head) {
			tail=head = newnode;
			counter++;
		}
		else {
			tail->next = newnode;
			tail=newnode;
			counter++;
		}
		tail->next = nullptr;
	}
	void insert_first(int value) {
		node* newnode = new node(value);
		newnode->next = head;
		head = newnode;
	}
	void display() {
		for (node* cur = head; cur; cur = cur->next) {
			cout << cur->data<<" ";
		}
		cout << endl;
		//cout << counter;
	}
	void search(int value) {
		for (node* cur = head; cur; cur = cur->next) {
			if (value == cur->data) {
				cout << "found";
				break;
			}
			if(cur->next==nullptr)
				cout << " not found";
		}
		
	}
	void insert_pos(int n,int value) {
		node* newnode = new node(value);
		if (n != 0 && n != 1 && n < counter) {
			int newcounter = 1;
			for (node* cur = head; cur; cur = cur->next, newcounter++) {
				if (n == newcounter+1) {
					newnode->next = cur->next;
					cur->next = newnode;
					break;
				}

			}
		}
	}
};
int main() {
	Linkedlist list;
	list.insert_end(10);
	list.insert_end(20);
	list.insert_end(30);
	list.insert_end(40);

	list.display();
	list.insert_pos(2,80);
	list.display();

	//list.search(90);
	return 0;
}