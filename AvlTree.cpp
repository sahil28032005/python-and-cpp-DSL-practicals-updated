#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data, balFact;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        balFact = 0;
    }
};
// uodate height after each rotation
Node *rotateLeft(Node *respectTo)
{
    Node *right = respectTo->right;
    Node *left = right->left;

    right->left = respectTo;
    respectTo->right = left;

    return right;
}
Node *roatateRight(Node *respectTo)
{
    Node *left = respectTo->left;
    Node *right = left->right;

    left->right = respectTo;
    respectTo->left = right;
    return left;
}
int findHeight(Node *root) // calculating height properly
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        return left > right ? left + 1 : right + 1;
    }
}
int getBalenceFactor(Node *root)
{
    if (root != NULL)
    {
        return (findHeight(root->left) - 1) - (findHeight(root->right) - 1);
    }
}

Node *insertIntoBst(Node *root, int data)
{
    // cout << "arrived in insert function" << endl;
    if (root == NULL)
    {
        cout << "created main root here.." << endl;
        return new Node(data); // this will be returned as an root
    }
    if (data > root->data)
    {
        root->right = insertIntoBst(root->right, data);
        cout << "inserted at right" << endl;
    }
    else
    {
        root->left = insertIntoBst(root->left, data);
        cout << "inserted at left" << endl;
    }
    root->balFact = getBalenceFactor(root);

    // cout << "not an balenceed tree" << endl;
    // here define cases for ll rr lr rl
    // for ll rotation
    if (root->balFact > 1 && data < root->left->data)
    {
        cout << "case for ll rotation" << endl;
        return roatateRight(root);
    }
    // rr rotation
    if (root->balFact < -1 && data > root->right->data)
    {
        cout << "case for rr rotations" << endl;
        return rotateLeft(root);
    }
    // lr rotatation
    if (root->balFact > 1 && data > root->left->data)
    {
        cout << "case for lr rotation" << endl;
        root->left = rotateLeft(root->left);
        return roatateRight(root);
    }
    // rl rotation case
    if (root->balFact < -1 && data < root->right->data)
    {
        cout << "case for rl rotation" << endl;
        root->right = roatateRight(root->right);
        return rotateLeft(root);
    }

    return root; // returns current root to previous call stack;
}

Node *createBst(Node *root, int data)
{
    // cout << "arrived in create bst" << endl;
    while (data != -1)
    {
        // cout << "arrived in while loop" << endl;
        root = insertIntoBst(root, data);
        cout << "enter next element to enter into bst otherwise press -1 for stop" << endl;
        cin >> data;
    }
    return root;
}

void traverseLevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    while (1)
    {
        int choise;
        cout << "ENTER CHOISE!\n"
             << "1) CREATE BST\n"
             << "2)DISPLAY\n"
             << "3)FIND HEIGHT\n"
             << "4)LL ROTATE\n"
             << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "enter data to add inside binary tree" << endl;
            int data;
            cin >> data;
            root = createBst(root, data);
            break;
        case 2:
            cout << "displaying data...." << endl;
            traverseLevelOrder(root);
            break;

        case 3:
            cout << findHeight(root) - 1 << endl;
            break;
        case 4:
            root = rotateLeft(root);
            break;
        case 5:
            root = roatateRight(root);
        }
    }

    return 0;
}