#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class operations
{
public:
    Node *front = NULL;
    Node *rear = NULL;
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void printQueue();
};
bool operations::isEmpty()
{
    return front == NULL ? true : false;
}
void operations::enqueue(int data)
{
    Node *n = new Node(data);
    if (front == NULL && rear == NULL)
    {
        front = rear = n;
    }
    else if (n == NULL)
    {
        cout << "queue is full storage exausted.." << endl;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}
void operations::printQueue()
{
    Node *n = front;
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}
int operations ::dequeue()
{
    if (isEmpty())
    {
        cout << "queue is empty" << endl;
    }

    else
    {
        Node *temp = front;
        front = front->next;
        int val = temp->data;
        free(temp);
        return val;
    }
}
int main()
{
    operations op;
    op.enqueue(12);
    op.enqueue(34);
    op.dequeue();
    op.dequeue();
    // op.dequeue();
    op.printQueue();
    return 0;
}