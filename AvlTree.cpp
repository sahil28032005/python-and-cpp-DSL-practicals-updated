#include <iostream>
#include <queue>
#include <string>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data, balFact;
    string key, value;
    // Node(int data)
    // {
    //     this->data = data;
    //     this->left = NULL;
    //     this->right = NULL;
    //     balFact = 0;
    // }
    Node(string key, string value)
    {
        this->key = key;
        this->value = value;
        this->left = NULL;
        this->right = NULL;
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
Node *findMin(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    else
    {
        findMin(root->left);
    }
}
Node *deleteFromBst(Node *root, string key)
{
    if (root == NULL)
    {
        cout << "data not found for deletion enter correct data" << endl;
        return NULL;
    }
    if (root->key == key)
    {
        cout << "KEY FOUND" << endl;
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left && root->right == NULL)
        {
            Node *left = root->left;
            delete root;
            return left;
        }
        if (root->right && root->left == NULL)
        {
            Node *right = root->right;
            delete root;
            return right;
        }
        if (root->left && root->right)
        {
            Node *rightMin=findMin(root->right);
            root->key=rightMin->key;
            root->value=rightMin->value;
            root->right=deleteFromBst(root->right,rightMin->key);
        }
    }
    else
    {
        if (key.compare(root->key) < 0)
        {
            // means finding in left part as key is smaller that roots key
            root->left = deleteFromBst(root->left, key);
        }
        else
        {
            // search in right part
            root->right = deleteFromBst(root->right, key);
        }
    }
    return root;
}
Node *insertIntoBst(Node *root, string key, string value)
{
    // cout << "arrived in insert function" << endl;
    if (root == NULL)
    {
        cout << "created main root here.." << endl;
        return new Node(key, value); // this will be returned as an root
    }
    if (key.compare(root->key) > 0)
    {
        root->right = insertIntoBst(root->right, key, value);
        cout << "inserted at right" << endl;
    }
    else
    {
        root->left = insertIntoBst(root->left, key, value);
        cout << "inserted at left" << endl;
    }
    // root->balFact = getBalenceFactor(root);

    // // cout << "not an balenceed tree" << endl;
    // // here define cases for ll rr lr rl
    // // for ll rotation
    // if (root->balFact > 1 && data < root->left->data)
    // {
    //     cout << "case for ll rotation" << endl;
    //     return roatateRight(root);
    // }
    // // rr rotation
    // if (root->balFact < -1 && data > root->right->data)
    // {
    //     cout << "case for rr rotations" << endl;
    //     return rotateLeft(root);
    // }
    // // lr rotatation
    // if (root->balFact > 1 && data > root->left->data)
    // {
    //     cout << "case for lr rotation" << endl;
    //     root->left = rotateLeft(root->left);
    //     return roatateRight(root);
    // }
    // // rl rotation case
    // if (root->balFact < -1 && data < root->right->data)
    // {
    //     cout << "case for rl rotation" << endl;
    //     root->right = roatateRight(root->right);
    //     return rotateLeft(root);
    // }

    return root; // returns current root to previous call stack;
}

Node *createBst(Node *root, string key, string value)
{
    // cout << "arrived in create bst" << endl;
    while (key != "n" && key != "N")
    {
        // cout << "arrived in while loop" << endl;
        root = insertIntoBst(root, key, value);
        cout << "enter key for next element to enter into bst otherwise press N/n for stop" << endl;
        cin >> key;
        if (key == "n" || key == "N")
        {
            continue;
        }
        cout << "enter  value of that key" << endl;
        cin >> value;
    }
    return root;
}
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << "KEY: " << root->key << " VALUE: " << root->value << endl;
    inorderTraversal(root->right);
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
            cout << temp->key << " ";
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
        string key, val;
        cout << "ENTER CHOISE!\n"
             << "1) CREATE BST\n"
             << "2)DISPLAY\n"
             << "3)FIND HEIGHT\n"
             << "4)LL ROTATE\n"
             << "6)DISPLAY ASCENDING\n"
             << "7)DELETE KEY\n"
             << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "enter kay to add inside  tree" << endl;
            cin >> key;
            cout << "enter value for provided key" << endl;
            cin >> val;
            root = createBst(root, key, val);
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
            break;
        case 6:
            inorderTraversal(root);
            break;
        case 7:
            cout << "Enter key to delete..." << endl;
            cin >> key;
            deleteFromBst(root, key);
        }
    }

    return 0;
}