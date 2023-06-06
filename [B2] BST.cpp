#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class BTree
{
private:
    Node *root;

    Node *insertNode(Node *node, int val)
    {
        if (node == NULL)
        {
            return new Node(val);
        }
        else
        {
            if (val < node->data)
            {
                node->leftChild = insertNode(node->leftChild, val);
            }
            else
            {
                node->rightChild = insertNode(node->rightChild, val);
            }
        }

        return node;
    }

    bool searchRecursive(Node *current, int value)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (value == current->data)
        {
            return true;
        }
        else if (value < current->data)
        {
            return searchRecursive(current->leftChild, value);
        }
        else
        {
            return searchRecursive(current->rightChild, value);
        }
    }

    void inorder(Node *node) {
        if(node!=NULL) {
            inorder(node->leftChild);
            cout << node->data << " ";
            inorder(node->rightChild);
        }
    }

    int height(Node *node) {
        if(node == NULL) {
            return 0;
        }

        int leftHeight = height(node->leftChild);
        int rightHeight = height(node->rightChild);

        return max(leftHeight,rightHeight) + 1;
    }

    int minimum() {

        Node *n = root;
        while(n->leftChild != NULL) {
            n = n->leftChild;
        }

        return n->data;
    }

    void swapNodes(Node *root) {
        if(root == NULL) {
            return;
        }

        Node* temp = root->leftChild;
        root->leftChild = root->rightChild;
        root->rightChild = temp;

        swapNodes(root->leftChild);
        swapNodes(root->rightChild);
        
    }

public:
    BTree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    bool search(int val) {
        return searchRecursive(root,val);
    }

    void display() {
        inorder(root);
    }

    int getHeight() {
        return height(root);
    }

    int getMinimum() {
        return minimum();
    }

    void swapVal() {
        swapNodes(root);
        display();
    }
};


int main() {
    BTree t1;
    int choice,val,numberOfNodes;

    do
    {
        cout << "\n1) Insert value" << endl;
        cout << "2) Display Tree" << endl;
        cout << "3) Get Minimum" << endl;
        cout << "4) Get Height" << endl;
        cout << "5) Swap Left with Right subtree" << endl;
        cout << "6) Exit" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch(choice) {
            case 1:
            cout << "Enter how many nodes you want to insert: "; cin >> numberOfNodes;
            for (int i = 0; i < numberOfNodes; i++)
            {
                cout << "Enter value: "; cin >> val;
                t1.insert(val);
            }
            cout << "Tree created successfully!" << endl;
            break;
            
            case 2:
            t1.display();
            cout << endl;
            break;
            
            case 3:
            cout << "Minimum in the tree: " << t1.getMinimum() << endl;
            break;
            
            case 4:
            cout << "Height of the tree: " << t1.getHeight() << endl;
            break;
            
            case 5:
            cout << "\nInorder traversal after swapping: " << endl;
            t1.swapVal();
            
            cout << endl;
            break;
            
            case 6:
            cout << "Exit successfully!" << endl;
            break;

            default:
            cout << "Invalid Choice!" << endl;
            break;
        }



    } while (choice != 6);
    
    return 0;
}
