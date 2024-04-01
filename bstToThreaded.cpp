#include <iostream>
#include <queue>
using namespace std;
// code to create node in binary tree
class Node
{
public:
    Node *left;
    Node *right;
    bool isThreaded = false;
    int data;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// finding leftMost child of binary tree
Node *returnLeftMost(Node *root)
{
    cout << "inside retur leftMost" << endl;
    if (root == NULL)
    {
        return root;
    }
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
}
// function to inorder traversal of threaded binary tree this needs an helper function called leftmost child finder
void inorderThreaded(Node *root)
{
    cout << "inide inorder thereded" << endl;
    if (root == NULL)
    {
        return;
    }
    else
    {
        Node *leftMost = returnLeftMost(root);
        // cout << "leftMost found " << leftMost->data;
        while (leftMost != NULL)
        {
            cout << leftMost->data << " ";
            if (leftMost->isThreaded)
            {
                cout << "found threaded" << endl;
                leftMost = leftMost->right;
                // cout << leftMost->data << endl;
            }
            else
            {
                leftMost = returnLeftMost(leftMost->right);
            }
        }
    }
}
void createInorderQueue(Node *root, queue<Node *> &myQueue) // here we are getting actual queue by an address
{
    cout << "inside createInorderQueue" << endl;
    if (root == NULL)
    {
        return;
    }
    createInorderQueue(root->left, myQueue);
    myQueue.push(root);
    createInorderQueue(root->right, myQueue);
}
void createThreadStructure(Node *root, queue<Node *> &myQueue) // also taken actual queue as an address
{
    cout << "inside create inorder structure" << endl;
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        createThreadStructure(root->left, myQueue);
    }
    myQueue.pop();
    if (root->right)
    {
        createThreadStructure(root->right, myQueue);
    }
    // here we are coming wherer we have to adjust nodes linking as threaded binary tree
    else
    {
        root->right = myQueue.front();
        root->isThreaded = true;
    }
}
void createBinaryToThreaded(Node *root)
{
    // cretaed queue to store inorder traversal
    cout << "inside cretaeBinaryToThreaded" << endl;
    queue<Node *> myQueue;
    createInorderQueue(root, myQueue);
    createThreadStructure(root, myQueue);
    inorderThreaded(root);
}
int main()
{
    Node *n1 = new Node(10); // making this as an root of bst
    Node *n2 = new Node(12);
    Node *n3 = new Node(33);
    Node *n4 = new Node(9);
    Node *n5 = new Node(3);
    // linking of nodes
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    createBinaryToThreaded(n1);
    // after completion tree will look like this
    // above are 5 nodes make  binary tree from it bylinking them
    //      10
    //     /  \
//       12    33
    //   /  \
//      9    3
    // expected output for this code is 9 12 3 10 33
    return 0;
}