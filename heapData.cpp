#include <iostream>
using namespace std;
class Node
{
public:
    Node *left, *right, *prev;
    int data;
    bool isOk;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->right = NULL;
        this->left = NULL;
        isOk = false;
    }
};
int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return max(left, right) + 1;
}
int getBalenceFact(Node *root)
{
    return (getHeight(root->left) - getHeight(root->right));
}
Node *insertIntoHeap(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    // checking status
    if (getBalenceFact(root) == 0)
    {
        root->isOk = true;
    }
    if (root->left == NULL || root->right == NULL && getBalenceFact(root) != 0)
    {
        // we are going in right side
        root->right = insertIntoHeap(root->right, data);
    }
    else
    {
        // we are going in left side
        if (root->isOk)
        {
            root->left = insertIntoHeap(root->left, data);
        }
        else{
            root->right = insertIntoHeap(root->right, data);
        }
    }
}
int main()
{

    return 0;
}