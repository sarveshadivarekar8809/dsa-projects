
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

node *findmin(node *root)
{
    while(root->left != nullptr)
        {
            root=root->left;
        }
    return root;
}

node *deletenode(node *root,int value){

    if(root==nullptr){
        cout<<"value not found:"<<endl;
        return root;
    }

    else if(value<root->data){

        root->left=deletenode(root->left,value);
    }

    else if(value>root->data){

        root->right=deletenode(root->right,value);
    }

    else{
        if(root->left==nullptr&&root->right==nullptr)
        {
            delete root;
            root=nullptr;
    
        }
    
        else if(root->left==nullptr){

            node *temp=root;
            root=root->left;
            delete temp;
        }
       else if(root->right==nullptr)
       {
           node *temp=root;
           root=root->right;
           delete temp;
       }

      else
       {
           node *temp=findmin(root->right);
           root->data=temp->data;
           root->right=deletenode(root->right,temp->data);
       } 
        
    }
    return root;
}
void remove()
{

int value;
    cout<<"enter the value you want to delete"<<endl;
    if(!(cin>>value)){

        cout<<"invalid input:"<<endl;
        return;
    }
    
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
    

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}
}
int main() {
    int choice;

    do {
        cout << "\n>>>>>> Binary Search Tree Menu <<<<<<" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout <<"3.Display"<<endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!" << endl;
            break;
        }

        switch(choice){
            case 1:
                    create();
                    break;

            case 2: 
                    remove();
                    break;

            case 3:
                   if(root==nullptr){

                       cout<<"BST is empty!"<<endl;
                       
                   }else{
                       cout<<"BST elements (In-order):";
                       display(root);
                       cout<<endl;
                   }
              break;

            case 4: 
                    cout<<"Exitin..."<<endl;
                    break;

            default:
                     cout<<"Invalid choice"<<endl;
        }
    }while(choice !=4);

    return 0;
}






        
