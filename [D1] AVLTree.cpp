#include <iostream>
using namespace std;

class Node {
    public:

    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


int max(int a, int b) {
    if(a > b) {
        return a;
    }
    return b;
}

class AVLTree {
    private:
    Node *root;

    int getHeight(Node *node) {
        if(node == NULL) {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node *node) {
        if(node == NULL) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateRight(Node *y) {
        Node *x = y->right;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
        x->height = max(getHeight(x->right),getHeight(x->left)) + 1;

        return x;
    }

    Node* leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
        x->height = max(getHeight(x->right),getHeight(x->left)) + 1;

        return y;
    }

    Node* insert(Node *node, int value) {
        if(node == NULL) {
            return new Node(value);
        }

        if(value < node->data) 
            node->left = insert(node->left,value);

        else if(value > node->data)
            node->right = insert(node->right,value);
            return node;
        node->height = 1 + max(getHeight(node->left),getHeight(node->right));

        int balance = getBalance(node);

        //1 LL
        if(balance > 1 && value < node->left->data) {
            rotateRight(node);
        }

        //2 RR
        if(balance < -1 && value > node->right->data) {
            leftRotate(node);

        }

        //3 LR
        if(balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            rotateRight(node);
        }

        //4 RL
        if(balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node *node) {
        if(node != NULL) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    public:
    AVLTree() {
        root = NULL;
    }

    void insert(int val) {
        root = insert(root,val);
    }

    void inorderTravesal() {
        inorderTraversal(root);
    }
};

int main() {

    AVLTree tree;

    tree.insert(30);
    tree.insert(10);
    tree.insert(20);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    tree.inorderTravesal();

}
