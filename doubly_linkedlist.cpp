#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
struct node {
	node* next{};
	node* prev{};
	int data;
	node(int data) :data(data) {};
};
class Double_linkedlist {
private:
	node* head{};
	node* tail{};
public:
	void insert_first(int value) {
		node* newnode = new node(value);
		if (!head) {
			tail = head = newnode;
		}
		else {
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
	}
	void insert_last(int value) {
		node* newnode = new node(value);
		if (!head) {
			tail = head = newnode;
		}
		else {
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
			tail->next = nullptr;
		}
	}
	void dislay() {
		for (node* cur = head; cur; cur = cur->next) {
			cout << cur->data << " ";

		}
		cout << endl;
	}
	void insert_after(int value, int target) {
		node* newnode = new node(value);
		for (node* cur = head; cur; cur = cur->next) {
			if (cur == tail) {
				this->insert_last(value);
				break;
			}
			else {
				newnode->next = cur->next;
				cur->next->prev = newnode;
				cur->next = newnode;
				newnode->prev = cur;
				break;
			}

		}
	}
	void delete_first() {
		node* temp = head;
		head = head->next;
		delete temp;
		head->prev = nullptr;
	}
	void delete_last() {
		node* temp = tail;
		tail = tail->prev;
		delete temp;
		tail->next = nullptr;
	}
	void delete_key(int key) {
		for (node* cur = head; cur; cur = cur->next) {
			if (cur->data == key) {
				node* temp = cur;
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete temp;
				break;
			}
		}
	}
	void display_back() {
		for (node* cur = tail; cur; cur = cur->prev) {
			cout << cur->data << " ";
		}
		cout << endl;

	}
};

int main() {
	Double_linkedlist list;
	list.insert_first(15);
	list.insert_first(18);
	list.insert_first(17);
	list.insert_first(13);
	list.insert_last(177);
	list.insert_after(98, 13);
	list.dislay();
	list.display_back();
	//list.delete_first();
	//list.delete_last();
	/*list.delete_key(98);
	*/




	return 0;
}