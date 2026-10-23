
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    
    node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

node* root = nullptr;


node* insert(node* root, int value) {
    if (root == nullptr) {
        return new node(value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else {
        cout << "Duplicates are not allowed" << endl;
    }

    return root;
}


void create() {
    int value;

    cout << "Enter value in BST: ";

    if (!(cin >> value)) {
        cout << "Invalid input!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    root = insert(root, value);
}


void display(node* root) {
    if (root == nullptr) {
        return;
    }

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main() {
    int choice;

    do {
        cout << "\n>>>>>> Binary Search Tree Menu <<<<<<" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!" << endl;
            break;
        }

        
