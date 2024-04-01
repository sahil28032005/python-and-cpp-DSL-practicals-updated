#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
Node *createFirstNode(int data, Node *head)
{
    Node *node = new Node(data);
    // head = node;//try after removing this sentence
    return node;
}
Node *insertAtTail(Node *head, int data)
{
    Node *actualHead = head;

    if (head == NULL)
    {
        return createFirstNode(data, head);
    }
    else
    {
        Node *node = new Node(data);
        while (head->next != NULL)
        {
            head = head->next;
        }
        //  cout<<head->data<< endl;
        head->next = node;
    }
    return actualHead;
}
void traverseList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *insertAtBeginning(Node *head, int data)
{

    if (head == NULL)
    {
        return createFirstNode(data, head);
    }
    else
    {
        Node *node = new Node(data);
        node->next = head;
        // head = node;
        return node;
    }
}
int findLength(struct Node *head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}
Node *insertAtIndex(int index, int data, Node *head)
{
    Node *node = new Node(data);
    if (index == 0)
    {
        return insertAtBeginning(head, data);
    }
    else if (index == findLength(head))
    {
        cout << "insert via use of insertAtLast function" << endl;
        insertAtTail(head, data);
    }
    else
    {
        int counter = 0;
        while (counter < index - 1)
        {
            head = head->next;
            counter++;
        }
        node->next = head->next;
        head->next = node;
    }
}
void searchNode(Node *head, int key)
{
    while (head!= NULL)
    {
        if (head->data == key)
        {
            cout << "your entered number is found in linked list" << endl;
            return;
        }
        head = head->next;
    }
    cout << "Your entered number is not found in linked list" << endl;
}
void sortLinkedList(Node *head)
{
    for (int i = 0; i < findLength(head); i++)
    {
        // cout << "outer";
        for (Node *i = head; i->next != NULL; i = i->next)
        {
            // cout << "inner";
            if (i->data > i->next->data)
            {
                int temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
            }
        }
    }
}
int main()
{
    Node *head = NULL;
    head = insertAtTail(head, 12); // 56 12 17
    traverseList(head);
    head = insertAtTail(head, 17);
    traverseList(head);
    head = insertAtTail(head, 17);
    traverseList(head);
    head = insertAtTail(head, 17);
    traverseList(head);
    head = insertAtTail(head, 1);
    traverseList(head);
    head = insertAtBeginning(head, 600);
    head = insertAtBeginning(head, 600);
    head = insertAtBeginning(head, 6070);
    traverseList(head);
    searchNode(head,6070);
    // sortLinkedList(head);
    // traverseList(head);

    return 0;
}