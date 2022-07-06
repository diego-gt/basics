// Binary Search Tree
// A tree which all the nodes follow the below properties:
// - The value of the key of the left sub-tree is less than the value of its parent (root) node's key
// - The value of the key of the right sub-tree is greater than or equal to the value of its parent (root) node's key

// Operations:
// - Search
// - Insert
// - Pre-order traversal
// - In-order traversal
// - Post-order traversal

#include <iostream>

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value) {
        data = value;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

struct BinaryTree {
    Node* root = nullptr;

    void Insert(int value){
        // todo: implement
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
    }

    Node* Search(int value){
        // todo: implement
    }

    BinaryTree() = default;

    ~BinaryTree() {
        delete root;
    }
};

int main() {
    std::cout << "Hello, world\n";

    return 0;
}