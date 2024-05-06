// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;
    bool isThreaded;
    Node(int data)
    {
        this->data = data;
        this->isThreaded = false;
        this->left = NULL;
        this->right = NULL;
    }
};
void createInorderList(Node *root, queue<Node *> *q)
{
    if (root == NULL)
    {
        return;
    }
    createInorderList(root->left, q);
    q->push(root);
    createInorderList(root->right, q);
}
void createThreadedStructure(Node *root, queue<Node *> *q)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        createThreadedStructure(root->left, q);
    }
    q->pop();
    if (root->right)
    {
        createThreadedStructure(root->right, q);
    }
    // at this stage we have node which we have to make threaded
    else
    {
        if (!q->empty())
        {
            cout << "inside threaded case" << endl;
            root->isThreaded = true;
            root->right = q->front();
        }
    }
}
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->isThreaded)
    {
        cout << root->data << " i am threaded node";
        return;
    }

    inorderTraversal(root->left);

    cout << root->data << " ";

    inorderTraversal(root->right);
}
int main()
{
    // Write C++ code here
    cout << "Try programiz.pro";
    // creating bst here
    Node *root = new Node(121); // supposing this as an root node
    Node *child1 = new Node(45);
    Node *child3 = new Node(67);
    Node *child4 = new Node(90);
    Node *child5 = new Node(1);
    Node *child6 = new Node(0);
    Node *child7 = new Node(2);
    Node *child8 = new Node(145);

    // structring bst
    root->left = child1;
    root->right = child8;

    child1->left = child5;
    child1->right = child3;

    child5->left = child6;
    child5->right = child7;

    child3->right = child4;

    // creatiing queue for inorder strucutre
    queue<Node *> q;
    createInorderList(root, &q);
    createThreadedStructure(root, &q);
    inorderTraversal(root);
    return 0;
}