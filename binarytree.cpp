#include <iostream>
using namespace std;

struct node 
{
    char data;
    struct node* left;
    struct node* right;
};

void preorder(node*);
void inorder(node*);
void postorder(node*);

int main(void) 
{
    node* root, * p1, * p2, * p3, * p4, * p5, * p6, * p7;
    p1 = new node;
    p1->data = '1';
    root = p1;
    p2 = new node;
    p2->data = '2';
    p3 = new node;
    p3->data = '3';
    p4 = new node;
    p4->data = '4';
    p5 = new node;
    p5->data = '5';
    p6 = new node;
    p6->data = '6';
    p7 = new node;
    p7->data = '7';

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p4->left = NULL;
    p4->right = NULL;
    p5->left = NULL;
    p5->right = NULL;
    p6->left = NULL;
    p6->right = NULL;
    p7->left = NULL;
    p7->right = NULL;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的前序走訪：";
    preorder(root);
    cout << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的中序走訪：";
    inorder(root);
    cout << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的後序走訪：";
    postorder(root);
    cout << endl;
}

void preorder(node* p) 
{
    if (p) 
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(node* p) 
{
    if (p) 
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void postorder(node* p) 
{
    if (p) 
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}