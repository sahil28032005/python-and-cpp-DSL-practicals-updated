#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(){};
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BinaryApproches
{
public:
    Node *cretaeBinaryTree(Node *node)
    {
        cout << "enter data" << endl;
        int data;
        cin >> data;
        node = new Node(data);

        if (node->data == -1)
        {
            return NULL;
        }

        cout << "enter data for left of " << node->data << endl;
        node->left = cretaeBinaryTree(node->left);

        cout << "enter data for right of " << node->data << endl;
        node->right = cretaeBinaryTree(node->right);

        return node;
    }
    void traverse(Node *root)
    {
        if (root != NULL)
        {
            traverse(root->left);
            cout << root->data << " ";
            traverse(root->right);
        }
        // cout<<"returning";
        return;
    }
};
int main()
{
    cout << "Ready for creating bst" << endl;
    BinaryApproches *app = new BinaryApproches();
    Node *node;
    // (*app).cretaeBinaryTree(node);
    // (*app).traverse(node);
    node = app->cretaeBinaryTree(node);
    app->traverse(node);

    return 0;
}