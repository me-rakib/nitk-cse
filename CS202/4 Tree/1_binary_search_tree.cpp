/*
https://gist.github.com/mycodeschool/44e1a9183ab0e931f729
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *create_new_node(Node *root, int data)
{
    Node *newP = new Node;
    newP->data = data;
    newP->left = NULL;
    newP->right = NULL;
    return newP;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = create_new_node(root, data);
    }
    else if (root->data >= data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data = data)
    {
        return true;
    }
    else if (root->data >= data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    int data;
    cout << "Search: ";
    cin >> data;
    if (search(root, data))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}