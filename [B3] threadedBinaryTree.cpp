#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    bool isThreaded;

    Node(int val)
    {
        data = val;
        left = NULL;
        
        right = NULL;
        isThreaded = false;
    }
};

class BST
{
private:
    Node *root;

    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    Node *insertNode(Node *node,int val) {
        if(node == NULL) {
            return new Node(val);
        }
        else {
            if(val < node->data) {
                node->left = insertNode(node->left,val);
            }
            else {
                node->right = insertNode(node->right,val);
            }
        }
    }

    Node *findPredecessor(Node *root) {
        if(root == NULL) {
            return NULL;
        }

        Node *predecessor = root->left;
        if(predecessor == NULL || predecessor->isThreaded) {
            return predecessor;
        }
        while(predecessor->right != NULL) {
            predecessor = predecessor->right;
        }
        return predecessor;
    }

    void createThreaded(Node *node) {
        if(node == NULL) {
            return;
        }

        if(node->left != NULL) {
            createThreaded(node->left);
            Node *predecessor = findPredecessor(node);
            predecessor->right = node;
            predecessor->isThreaded = true;
        }

        if(node->right != NULL) {
            createThreaded(node->right);
        }
    }

    Node *findLeftMost(Node *node) {
        Node *current = node;
        while(current != NULL && current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    void inorderThreaded(Node *node) {
        Node *current = findLeftMost(node);

        while(current != NULL) {
            cout << current->data << "->";

            if(current->isThreaded) {
                current = current->right;
            }
            else {
                current = findLeftMost(current->right);
            }
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    void display()
    {
        inorderThreaded(root);
    }

    void createThread() {
        createThreaded(root);
    }

};

int main()
{
    BST tree;
    int choice,value;

    
    do {
        cout << "\n1) Insert value" << endl;
        cout << "2) Display inorder threaded tree" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: "; cin >> value;
            tree.insert(value);
            break;

        case 2:
        tree.createThread();
        tree.display();
        break;
        
        default:
            cout << "Not valid" << endl;
            break;
        }

    }while(choice != 2);

    return 0;
}
