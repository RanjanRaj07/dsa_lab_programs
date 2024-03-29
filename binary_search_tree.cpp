#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    Node* lchild;
    Node* rchild;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->lchild = newNode->rchild = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value){
    if(root == nullptr){
        root = createNode(value);
    }else if(value <= root->data){
        root->lchild = insertNode(root->lchild, value);
    }else{
        root->rchild = insertNode(root->rchild, value);
    }
    return root;
}

Node* searchNode(Node* root, int key, Node** parent){
    Node* temp;
    temp = root;
    while(temp != nullptr){
        if(temp->data==key){
            cout << "\n The element" << temp->data << " is present\n";
            return temp;
        }
        *parent = temp;
        if(temp->data > key)
            temp = temp->lchild;
        else
            temp = temp->rchild;
    }
    return nullptr;
}

void inorderTraversal(Node* root){
    if(root != nullptr){
        inorderTraversal(root->lchild);
        cout << root->data << " ";
        inorderTraversal(root->rchild);
    }
}

void preorderTraversal(Node* root){
    if(root != nullptr){
        cout << root->data << " ";
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }
}

void postorderTraversal(Node* root){
    if(root != nullptr){
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
        cout << root->data << " ";
    }
}

int main(){
    Node* root = nullptr;
    int choice, key;

    do{
        cout << "\nBinary search tree operations\n";
        cout << "1. Create\n";
        cout << "2. Search\n";
        cout << "3. Recursive Traversals\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: \n";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            int val, ans;
            ans=0;
            do{
                cout << "Enter the element\t";
                cin >> val;
                cout <<"\ndo you want to add more elements(0/1)\t";
                cin >> ans;
                root = insertNode(root, val);
            }while(ans==1);
            break;

        case 2:
            cout << "Enter the key to search: ";
            cin >> key;
            Node* parent;
            Node* temp;
            temp = searchNode(root, key, &parent);
            if(temp != nullptr){
                cout << "The parent of the node "<<temp->data<<" is "<< parent->data<< endl;
            }
            else{
                cout << "The Node with data "<<key<<" is not present in the BST\n";
            }
            break;
        
        case 3:
            if(root == nullptr){
                cout << "The BST is not created\n";
            }
            else{
                cout << "\nThe inorder display is \t";
                inorderTraversal(root);
                cout << "\nThe preorder display is \t";
                preorderTraversal(root);
                cout << "\nThe postorder display is \t";
                postorderTraversal(root);
            }
            break;
        
        default:
            if(choice != 4)
                cout << "Invalid choice\n";
            break;
        }
    }while(choice != 4);
    return 0;
}

