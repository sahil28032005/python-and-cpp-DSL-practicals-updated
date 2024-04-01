#include <iostream>
using namespace std;
bool flag = false;
#include <queue>
#include <stack>
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    // First recur on left child
    inOrderTraversal(root->left);

    // Then print the data of node
    cout << root->data << " ";

    // Now recur on right child
    inOrderTraversal(root->right);
}
Node *findCorrectPos(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    else if (data >= (root->data))
    {
        root->right = findCorrectPos(root->right, data); //
        cout << "inserted at right position" << endl;
    }
    else
    {
        root->left = findCorrectPos(root->left, data);
        cout << "inserted at left position" << endl;
    }
    return root;
}
Node *takeInput(int data, Node *root)
{
    while (data != -1)
    {
        root = findCorrectPos(root, data);
        cout << "insert data to insert in BST" << endl;
        cin >> data;
    }
    return root;
}

Node *findElement(Node *root, int data)
{
    if (root == NULL)
    {
        return nullptr;
    }
    if (root->data == data)
    {
        // flag = true;
        return root;
    }
    else if (root != NULL)
    {
        if (data >= root->data)
        {
            return findElement(root->right, data);
        }
        else
        {
            return findElement(root->left, data);
        }
    }
}
void swapNodes(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    swapNodes(root->left);
    swapNodes(root->right);
    if (root->right != NULL or root->left != NULL)
    {
        Node *temp = root->right;
        root->right = root->left;
        root->left = temp;
    }
}
void reverseInorderNonRecursive(Node *root)
{
    stack<Node *> st;
    while (root != NULL)
    {
        st.push(root);
        root = root->right;
        while (root == NULL && !st.empty())
        {
            Node *popped = st.top();
            st.pop();
            cout << popped->data << " ";
            root=popped->left;
        }
    }
}
void levelOrderTraversal(Node *root)
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
int findDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = findDepth(root->left);
    int right = findDepth(root->right);
    return left > right ? left : right;
}
Node *findMin(Node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return findMin(root->left);
}
Node *findMax(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findMax(root->right);
}
Node *deleteFromTree(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        // case where er are trying to delete the leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            cout << "deleted leaf element" << endl;
            return NULL;
        }
        // case where we are trying to delete node having only left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *successor = root->left; // handle links linked with that node for further management
            delete root;
            cout << "deleted element having only left childrens" << endl;
            return successor;
        }
        if (root->right != NULL && root->left == NULL)
        {
            Node *successor = root->right; // handle links linked with that node for further management
            delete root;
            cout << "deleted element having only right childrens" << endl;
            return successor;
        }
        if (root->right != NULL && root->left != NULL)
        {
            int maxRight = (findMax(root->left))->data;
            cout << "max element foundin the right is " << maxRight << endl; // first finding maximum element fromleft subtree
            root->data = maxRight;                                           // assigining tahat max data to root
            root->left = deleteFromTree(root->left, maxRight);               // delete the node whose connection exists still
            return root;
        }
    }
    else
    {
        if (data >= root->data)
        {
            // bigger search in right
            root->right = deleteFromTree(root->right, data);
        }
        else
        {
            // smaller search nin left subtree
            root->left = deleteFromTree(root->left, data);
        }
    }
    return root; // done as an good practice but still working when i remove it
}
void inOrderNonRecursive(Node *root)
{
    stack<Node *> st;

    while (root != NULL)
    {
        st.push(root);
        root = root->left;
        while (root == NULL && !st.empty()) // checking weather root is null and stack has at least one element
        {
            Node *popped = st.top();
            st.pop();
            cout << popped->data << " ";
            root = popped->right;
        }
    }
}

int main()
{
    Node *n = NULL;
    int choise = 0;
    Node *result;
    while (true)
    {
        cout << "1)cretae binary search tree...\n2)insert data into BST...\n3)Display Binary search tree...\n4)Search element \n5)Exit"
             << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Enter data to insert into BST" << endl;
            int data;
            cin >> data;
            n = takeInput(data, n);
            break;
        case 2:
            cout << "Enter data to insert into BST" << endl;
            int insertData;
            cin >> insertData;
            n = findCorrectPos(n, insertData);
            break;
        case 3:
            cout << "Binary Search Tree: ";
            inOrderTraversal(n);
            cout << endl;
            break;
        case 4:
            int searchData;
            cout << "Enter element to search in BST" << endl;
            cin >> searchData;
            result = findElement(n, searchData);
            if (result != nullptr)
            {
                cout << "Element found in BST" << result->data << endl;
            }
            else
            {
                cout << "Element not found in BST" << endl;
            }
            break;
        case 5:
            swapNodes(n);
            break;
        case 6:
            levelOrderTraversal(n);
            break;
        case 7:
            cout << "Enter data to delete from tree" << endl;
            int deleteData;
            cin >> deleteData;
            deleteFromTree(n, deleteData);
            break;
        case 8:
            inOrderNonRecursive(n);
            break;
        case 9:
             reverseInorderNonRecursive(n);
             break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}