#include <iostream>

struct Node {
	int data;
	Node* next = nullptr;

	Node(int value) {
		data = value;
	}
};

struct LinkedList {
	Node* head = nullptr;

	// Add a new node to the end of the linked list
	void Append(int value){
		Node* tail = new Node(value);

		// Create head if required
		if (head == nullptr) {
			head = tail;
			return;
		}

		Node* last = head;

		// traverse list until last node
		while (last->next != nullptr) {
			last = last->next;
		}

		last->next = tail;
	}
	
	void Push(int value){
		// shuffle new node with the current head
		Node* new_head = new Node(value);
		new_head->next = head;
		head = new_head;
	}

	void InsertAfter(Node* ref, int value) {
		if (ref == nullptr) {
			std::cerr << "Reference node can not be empty.\n";
			return;
		}

		Node* new_node = new Node(value);
		new_node->next = ref->next;
		ref->next = new_node;
	}

	void Print() {
		if (head != nullptr) {
			std::cout << "Head: " << head->data << "\n";
			Node* tmp = nullptr;
			if (head->next != nullptr) {
				tmp = head->next;
			}
			
			while (tmp != nullptr) {
				std::string label = (tmp->next != nullptr) ? "Body: " : "Tail: ";
				std::cout << label << tmp->data << "\n";
				tmp = tmp->next;
			}
			std::cout << "\n";
		} else {
			std::cout << "Empty list\n";
		}
	}
};


int main() {
	// todo: create a linked list, add values, remove values, print it
	LinkedList ll;

	ll.Append(9);
	ll.Append(2);
	ll.Append(7);

	ll.Print();

	ll.Push(3);
	ll.Print();

	return 0;
}
