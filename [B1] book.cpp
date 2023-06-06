#include<iostream>
using namespace std;

class node
{
    char data;
    node * left;
    node * right;
    public:
    friend class Book;
    node(char val)
    {
        data = val ;
        left = right = NULL;
    }
};

class Book
{
    node *root ;
    public:
    Book ()
    {
        root = NULL;
    }
    node *create();
    void inorder(node * n);
    void preorder(node *n);
    void postorder(node *n);
};

node * Book::create()
{   
    char val;
    cout<<"\nEnter the value (Enter # for No value ) :- ";
    cin>>val;

    if (val == '#')
    {
        return NULL;
    }    
    node *p = new node(val);
    if (root == NULL)
    {
        root =p;
    }
    cout<<"\nEnter The left child for "<<val;
    p->left = create();
    cout<<"\nEnter the right child for "<<val;
    p->right = create();

    return p;
}

void Book :: preorder(node *n)
{   
    if (root == NULL)
    {
        cout<<"Tree is Empty ";
        return;
    }
    if (n != NULL)
    {
        cout<<n->data;
        preorder(n->left);
        preorder(n->right);
    }
}
void Book :: inorder(node *n)
{   
    if (root == NULL)
    {
        cout<<"Tree is Empty ";
        return;
    }
    if (n != NULL)
    {
        inorder(n->left);
        cout<<n->data;
        inorder(n->right);
    }
}
void Book :: postorder(node *n)
{   
    if (root == NULL)
    {
        cout<<"Tree is Empty ";
        return;
    }
    if (n != NULL)
    {
        inorder(n->left);
        inorder(n->right);
        cout<<n->data;
    }
}


int main()
{
    cout<<"\nHello";
    node *p;
    Book b;
    p = b.create();
    cout<<"\nPreorder is :- ";
    b.preorder(p);
    cout<<"\nInorder is :- ";
    b.inorder(p);
    cout<<"\nPostorder is :- ";
    b.postorder(p);

}
