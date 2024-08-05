#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }
};
//checkpoint
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
void reverSeUsingRecursion(Node *current, Node *prev)
{
    if (current == NULL)
    {
        printLinkedList(prev);
        return;
    }
    // perform reverse logic
    Node *next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    reverSeUsingRecursion(current, prev);
}
Node *reverseLinkedList(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        // simoly cahnge ppointer at this step
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    Node *n1 = new Node(12);
    Node *n2 = new Node(67);
    Node *n3 = new Node(56);
    n1->next = n2;
    n2->next = n3;

    // creating head node
    Node *head = n1; // acting n1 as an head of linked list
    printLinkedList(head);
    cout<<endl;
    // Node *newHead=reverseLinkedList(head);//successfully reverse linked list
    Node *prev = NULL;
    reverSeUsingRecursion(head, prev);
    return 0;
}