#include <iostream>
using namespace std;

class BinaryNode
{
public:
    int data;
    BinaryNode *left, *right;
    BinaryNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Traversal
{
public:
    void preOrder(BinaryNode *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
};

int main()
{
    BinaryNode *n0 = new BinaryNode(1); // root node
    BinaryNode *n1 = new BinaryNode(7);
    BinaryNode *n2 = new BinaryNode(9);
    BinaryNode *n3 = new BinaryNode(2);
    BinaryNode *n4 = new BinaryNode(6);
    BinaryNode *n5 = new BinaryNode(9);
    BinaryNode *n6 = new BinaryNode(5);
    BinaryNode *n7 = new BinaryNode(11);
    BinaryNode *n8 = new BinaryNode(5);

    n0->left = n1;
    n0->right = n2;

    n1->left = n3;
    n1->right = n4;

    n4->left = n6;
    n4->right = n7;

    n2->right = n5;

    n5->left = n8;

    Traversal t;
    t.preOrder(n0);
    return 0;
}