#include <iostream>
using namespace std;
class Node
{
public:
    Node *left, *right, *prev;
    int data;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->right = NULL;
        this->left = NULL;
    }
};
int main()
{
    
    return 0;
}