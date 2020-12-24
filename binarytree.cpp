// 20201224 CHEN PEI CHI 1.0
// 20201225 CHEN PEI CHI 2.0
// 20201225 CHEN PEI CHI 3.0

#include <iostream>
#include <queue>
using namespace std;

struct node 
{
    char data;
    struct node* left;
    struct node* right;
};

queue<node*> qu;

void levelorder1(node*);
void preorder1(node*);
void inorder1(node*);
void postorder1(node*);

void levelorder2(node*);
void preorder2(node*);
void inorder2(node*);
void postorder2(node*);

void levelorder3(node*);
void preorder3(node*);
void inorder3(node*);
void postorder3(node*);

int main(void) 
{
    // {1, 2, 3, 4, 5, 6, 7, }
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

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的寬度優先：";
    levelorder1(root);
    cout << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的前序走訪：";
    preorder1(root);
    cout << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的中序走訪：";
    inorder1(root);
    cout << endl;

    cout << "{1, 2, 3, 4, 5, 6, 7, } 的後序走訪：";
    postorder1(root);
    cout << endl;

    // 分隔線
    cout << "-" << endl;

    // {7, 6, 5, 4, 3, 2, 1, }
    node* aroot, * a1, * a2, * a3, * a4, * a5, * a6, * a7;
    a1 = new node;
    a1->data = '7';
    aroot = a1;
    a2 = new node;
    a2->data = '6';
    a3 = new node;
    a3->data = '5';
    a4 = new node;
    a4->data = '4';
    a5 = new node;
    a5->data = '3';
    a6 = new node;
    a6->data = '2';
    a7 = new node;
    a7->data = '1';

    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    a3->left = a6;
    a3->right = a7;
    a4->left = NULL;
    a4->right = NULL;
    a5->left = NULL;
    a5->right = NULL;
    a6->left = NULL;
    a6->right = NULL;
    a7->left = NULL;
    a7->right = NULL;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的寬度優先：";
    levelorder2(aroot);
    cout << endl;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的前序走訪：";
    preorder2(aroot);
    cout << endl;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的中序走訪：";
    inorder2(aroot);
    cout << endl;

    cout << "{7, 6, 5, 4, 3, 2, 1, } 的後序走訪：";
    postorder2(aroot);
    cout << endl;

    // 分隔線
    cout << "-" << endl;

    // {4, 6, 5, 2, 7, 1, 3, }
    node* broot, * b1, * b2, * b3, * b4, * b5, * b6, * b7;
    b1 = new node;
    b1->data = '4';
    broot = b1;
    b2 = new node;
    b2->data = '6';
    b3 = new node;
    b3->data = '5';
    b4 = new node;
    b4->data = '2';
    b5 = new node;
    b5->data = '7';
    b6 = new node;
    b6->data = '1';
    b7 = new node;
    b7->data = '3';

    b1->left = b2;
    b1->right = b3;
    b2->left = b4;
    b2->right = b5;
    b3->left = b6;
    b3->right = b7;
    b4->left = NULL;
    b4->right = NULL;
    b5->left = NULL;
    b5->right = NULL;
    b6->left = NULL;
    b6->right = NULL;
    b7->left = NULL;
    b7->right = NULL;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的寬度優先：";
    levelorder3(broot);
    cout << endl;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的前序走訪：";
    preorder3(broot);
    cout << endl;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的中序走訪：";
    inorder3(broot);
    cout << endl;

    cout << "{4, 6, 5, 2, 7, 1, 3, } 的後序走訪：";
    postorder3(broot);
    cout << endl;
}

// {1, 2, 3, 4, 5, 6, 7, }
void levelorder1(node* now) 
{
    qu.push(now);
    while (!qu.empty()) 
    {
        cout << qu.front()->data << " ";
        if (qu.front()->left != NULL) 
        {
            qu.push(qu.front()->left);
        }
        if (qu.front()->right != NULL) 
        {
            qu.push(qu.front()->right);
        }
        qu.pop();
    }
}

void breadthfirst1(node* p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder1(p->left);
        preorder1(p->right);
    }
}

void preorder1(node* p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder1(p->left);
        preorder1(p->right);
    }
}

void inorder1(node* p)
{
    if (p)
    {
        inorder1(p->left);
        cout << p->data << " ";
        inorder1(p->right);
    }
}

void postorder1(node* p)
{
    if (p)
    {
        postorder1(p->left);
        postorder1(p->right);
        cout << p->data << " ";
    }
}

// {7, 6, 5, 4, 3, 2, 1, }
void levelorder2(node* now)
{
    qu.push(now);
    while (!qu.empty())
    {
        cout << qu.front()->data << " ";
        if (qu.front()->left != NULL)
        {
            qu.push(qu.front()->left);
        }
        if (qu.front()->right != NULL)
        {
            qu.push(qu.front()->right);
        }
        qu.pop();
    }
}

void preorder2(node* a) 
{
    if (a) 
    {
        cout << a->data << " ";
        preorder2(a->left);
        preorder2(a->right);
    }
}

void inorder2(node* a) 
{
    if (a) 
    {
        inorder2(a->left);
        cout << a->data << " ";
        inorder2(a->right);
    }
}

void postorder2(node* a) 
{
    if (a) 
    {
        postorder2(a->left);
        postorder2(a->right);
        cout << a->data << " ";
    }
}

// {4, 6, 5, 2, 7, 1, 3, }
void levelorder3(node* now)
{
    qu.push(now);
    while (!qu.empty())
    {
        cout << qu.front()->data << " ";
        if (qu.front()->left != NULL)
        {
            qu.push(qu.front()->left);
        }
        if (qu.front()->right != NULL)
        {
            qu.push(qu.front()->right);
        }
        qu.pop();
    }
}

void preorder3(node* b)
{
    if (b)
    {
        cout << b->data << " ";
        preorder3(b->left);
        preorder3(b->right);
    }
}

void inorder3(node* b)
{
    if (b)
    {
        inorder3(b->left);
        cout << b->data << " ";
        inorder3(b->right);
    }
}

void postorder3(node* b)
{
    if (b)
    {
        postorder3(b->left);
        postorder3(b->right);
        cout << b->data << " ";
    }
}