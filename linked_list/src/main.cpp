// Linked list implementation by Diego Garza : 2022-07-04
// Method names based on C++ <vector> from the standard library

#include <iostream>

struct Node {
	int data;
	Node* next = nullptr;

	Node(int value) {
		data = value;
	}
	
	~Node() {
		delete next;
	}
};

struct LinkedList {
	Node* head = nullptr;

	// Create an empty list by default
	LinkedList() = default;

	// Create a list with a head
	LinkedList(int value) {
		head = new Node(value);
	}

	// Destroy the list
	~LinkedList() {
		delete head;
	}

	// Add a new node to the end of the linked list
	void PushBack(int value){
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
	
	// Add a new node as the head of the linked list
	void Push(int value){
		// shuffle new node with the current head
		Node* new_head = new Node(value);
		new_head->next = head;
		head = new_head;
	}

	// Insert a new node after a reference node in the linked list
	void InsertAfter(Node* ref, int value) {
		if (ref == nullptr) {
			std::cerr << "Reference node can not be empty.\n";
			return;
		}

		Node* new_node = new Node(value);
		new_node->next = ref->next;
		ref->next = new_node;
	}

	// Removes the last element of the linked list
	void PopBack() {
		// Don't do anything on an empty list
		if (head == nullptr) {
			return;
		}

		// Keep track of our position on the list
		Node* prev = head;
		Node* last = head->next;

		// Traverse the whole list until the final node
		while(last->next != nullptr){
			prev = last;
			last = last->next;
		}

		// Set the previous node as the new last
		prev->next = nullptr;
		// Actually delete the node
		delete last;
	}

	// Remove a given node from the list
	void Remove(Node* node) {
		// Don't do anything on an empty list
		if (head == nullptr) {
			return;
		}

		// Find the previous and given node in the list
		Node* prev = head;
		Node* current = head;

		// Traverse the list until finding the node
		while (current != node) {
			if (current->next == nullptr) {
				// We're on the end of the list and we didn't find the node to delete
				return;
			}
			prev = current;
			current = current->next;
		}

		// shuffle the link of the nodes
		prev->next = node->next;

		delete current;	
	}

	// Find first element of the linked list with the given value
	Node* FindFirst(int value) {
		if (head == nullptr) {
			std::cout << "Can not search an empty list.\n";
			return nullptr;
		}

		Node* res = head;

		while (res->data != value) {
			if (res->next == nullptr) {
				std::cout << "No element found with the given value.\n";
				return nullptr;
			}
			res = res->next;
		}
		
		std::cout << "Found with the given value.\n" << "\t" << res->data << "\n";

		return res;
	}

	// Print the elements of the lists
	void Print() {
		if (head != nullptr) {
			std::cout << "Head: " << head->data << "\n";
			
			if (head->next == nullptr) {
				std::cout << "\n";
				return;
			}
			
			Node* tmp = head->next;
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

	ll.PushBack(1);
	ll.PushBack(2);
	ll.PushBack(3);
	ll.PushBack(4);
	ll.Print();

	Node* n3 = ll.FindFirst(3);

	ll.InsertAfter(n3, 5);
	ll.Print();

	ll.Remove(n3);
	ll.Print();

	return 0;
}
