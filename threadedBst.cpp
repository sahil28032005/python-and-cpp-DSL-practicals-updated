#include <iostream>
using namespace std;
#include <queue>
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    bool isRight;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->isRight = false;
    }
};
Node *createTbt(Node *root, int data)
{
    // case where root of tree made
    if (data == -1)
    {
        return root;
    }
    Node *prev = root;
    if (prev == NULL)
    {
        Node *n = new Node(data);
        return n; // returned root of tree
    }

    while (prev != NULL)
    {

        if (data < prev->data)
        {
            if (prev->left == NULL)
            {
                Node *n = new Node(data);
                prev->left = n;
                if (prev->left->isRight == false)
                {
                    prev->left->right = prev;
                    prev->left->isRight = true;
                    break;
                }
            }
            else
            {
                prev = prev->left;
            }
        }
        else
        {
            if (prev->right == NULL || prev->isRight)
            {
                Node *n = new Node(data);
                prev->right = n;
                if (prev->isRight && prev->right->data == n->data)
                {
                    n->right = root;
                    n->isRight = true;
                }
                prev->isRight = false;
                cout << "added at right" << endl;
                break;
            }
            else
            {
                prev = prev->right;
            }
        }
    }
    return root;
}
Node *levelOrderTraversal(Node *root)
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
            cout << temp->data << temp->isRight;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right && temp->isRight == false)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *findMax(Node *root)
{
    if (root->isRight)
    {
        return root;
    }
    else
    {
        return findMax(root->right);
    }
}
Node *deleteFromTbt(Node *root, int data, Node *actualRoot)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        //case where root left not null but root right is pointer t actual root
        if(root->left==NULL && root->isRight){
            int max=(findMax(root->left))->data;
            root->data = max;
            // root->left=
        }
        // case where node to be deleted having 2 childs present
        if (root->left != NULL && root->right != NULL && root->isRight == false)
        {
            int data = (findMax(root->left))->data;
            root->data = data;
            root->right = deleteFromTbt(root->left, data, actualRoot);
        }
        // case where deleting simple leaf node having 2 childs present as nULL
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // memory of that node gets freed and avaliable for reallocation
            return NULL;
        }
        // case where i am deleting node having right inorder predessor value
        if (root->left == NULL && root->isRight)
        {
            // case where leaf node parent having no children for reference your one note

            if (root->right->data == actualRoot->data)
            {
                return root->right; // handeled seperately where we are deleting rightmost lead nodes
            }
            // case wherer right node pointing middle inorder but its not root
            if (root->left == NULL && root->isRight && root->right->data != actualRoot->data)
            {
                delete root;
                return NULL;
            }
        }
        else if (root->left == NULL && !root->isRight)
        {
            Node *successor = root->right;
            delete root;
            return successor;
        }
    }
    else
    {
        if (data > root->data)
        {
            root->right = deleteFromTbt(root->right, data, actualRoot);
        }
        else
        {
            root->left = deleteFromTbt(root->left, data, actualRoot);
        }
    }
}
int main()
{
    Node *first = nullptr;
    int opt;

    while (true)
    {
        cout << "enter your choise" << endl;
        cout << "1)insert into TBT" << endl;
        cout << "2)perform inorder traversal" << endl;
        cin >> opt;
        switch (opt)
        {
        case /* constant-expression */ 1:
            /* code */
            cout << "enter data to insert" << endl;
            int data;
            cin >> data;
            first = createTbt(first, data);
            cout << "added data" << endl;
            break;
        case 2:
            levelOrderTraversal(first);
            break;
        default:
            break;
        }
    }

    return 0;
}
// another way to pass dynamic root and actual root to handle some cases where getting right end child problemm