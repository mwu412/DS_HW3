#include <iostream>
#include <string>
using namespace std;

class linkedlist {

private:
	class node {
	public:
		string gift;
		string price;
		node *link;
		node(string gift, string price) {
			this->gift = gift;
			this->price = price;
			link = NULL;
		}

	};
	node *first;
	node *last;

public:
	linkedlist() {
		first = last = NULL;
	}
	bool Empty() {
		return first == NULL;
	}
	void InsertBack(string gift, string price) {
		node* search = first;
		while (search) {								//check for repetitve price
			if (search->price == price) return;
			search = search->link;
		}
		node* newone = new node(gift, price);
		if (first) {
			last->link = newone;
			last = newone;
		}
		else { //empty list
			first = last = new node(gift, price);
		}
	}
	void InsertAfter(string gift, string price, string targetPrice) {
		node* search = first;
		while (search) {								//check for repetitve price
			if (search->price == price) return;
			search = search->link;
		}
		node* newone = new node(gift, price);
		search = first;
		while (search) {
			if (targetPrice == search->price) {
				newone->link = search->link;
				search->link = newone;
				if (newone->link == NULL) last = newone;
				break;
			}
			search = search->link;
		}
	}
	void Delete(string targetPrice) {
		node *search = first, *previous = NULL;
		while (search) {
			if (targetPrice == search->price) {
				if (search == first) {
					first = first->link;
					delete search;
				}
				else {
					previous->link = search->link;
					delete search;
					search = NULL;
					if (previous->link == NULL) last = previous;
				}
				break;
			}
			previous = search;
			search = search->link;
		}
	}
	void Reverse() {
		if (!Empty()) {
			node *current = first, *previous = NULL;
			while (current) {
				node *r = previous;
				previous = current;
				current = current->link;
				previous->link = r;
			}
			last = first;
			last->link = NULL;
			first = previous;
		}
	}
	void Print() {
		if (Empty()) cout << "Empty\n";
		else {
			cout << "List\n";
			node *current = first;
			while (current->link) {
				cout << '(' << current->gift << ',' << current->price << ")->";
				current = current->link;
			}
			cout << '(' << current->gift << ',' << current->price << ')' << endl;
		}
	}
};

int main() {
	linkedlist list;
	string in;

	do {
		cin >> in;
		string gift, price, targetPrice;
		if (in == "InsertBack") {
			cin >> gift;
			cin >> price;
			list.InsertBack(gift, price);
		}
		else if (in == "InsertAfter") {
			cin >> gift;
			cin >> price;
			cin >> targetPrice;
			list.InsertAfter(gift, price, targetPrice);
		}
		else if (in == "Delete") {
			cin >> price;
			list.Delete(price);
		}
		else if (in == "Reverse") {
			list.Reverse();
		}
	} while (in != "End");
	list.Print();
	system("pause");
	return 0;
}

