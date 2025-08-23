#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *createnode(int data){
    node *n = new node;
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

node* insert(node* root, int key){
    if (root == nullptr) 
        return createnode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        cout << "Already in BST\n";
    return root;
}

node* getSuccessor(node* root) {
    node* current = root->right;
    while (current != nullptr && current->left != nullptr)
        current = current->left;
    return current; 
}

node* deleteNode(node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;  
            return temp;
        }
    
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;   
            return temp;
        }

        node* succ = getSuccessor(root);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(){
    node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal:";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "deleting 30:";
    inorder(root);
    cout << endl;

    return 0;
}