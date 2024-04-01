#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int size, front, rear;
    int *arr;

    CircularQueue(int size)
    {
        this->arr = (int *)malloc(sizeof(int) * size);
        front = rear = -1;
        this->size = size;
    }
};
class operations
{
public:
    CircularQueue *q1 = new CircularQueue(6);
    void enqueueF(int data);
    void dequeueF();
    void enqueueR(int data);
    void dequeueR();

    bool isEmpty();
    bool isFull();
    void printQueue();
};
bool operations::isEmpty()
{
    return q1->front == q1->rear ? true : false;
}
bool operations::isFull()
{
    return q1->front == (q1->rear + 1) % (q1->size) ? true : false;
}
void operations::enqueueF(int data)
{
    if (isFull())
    {
        cout << "queue is full" << endl;
    }
    else if (q1->front == -1 && q1->rear == -1)
    {
        q1->front = q1->rear = 0;
        q1->arr[q1->front] = data;
    }
    else
    {
        q1->front = ((q1->front - 1) + q1->size) % q1->size;
        q1->arr[q1->front] = data;
    }
}
void operations::dequeueF()
{
    if (isEmpty())
        cout << "queue is empty" << endl;
    else
    {
        q1->front = (q1->front + 1) % q1->size;
    }
}
void operations::printQueue()
{
    int i = 0;
    for (i = q1->front; i != q1->rear; i = (i + 1) % q1->size)
    {
        cout << q1->arr[i] << " ";
    }
    cout << q1->arr[i] << endl;
    for (int i = 0; i < q1->size; i++)
    {
        cout << q1->arr[i] << " ";
    }
    cout << endl;
    cout << "current front and rear are " << q1->front << " and " << q1->rear << endl;
}
void operations::enqueueR(int data)
{
    if (isFull())
    {
        cout << "queue is full" << endl;
    }
    else if (q1->front == -1 && q1->rear == -1)
    {
        q1->front = q1->rear = 0;
        q1->arr[q1->front] = data;
    }
    else
    {
        q1->rear = (q1->rear + 1) % q1->size;
        q1->arr[q1->rear] = data;
    }
}
void operations::dequeueR()
{
    if (isEmpty())
        cout << "queue is empty" << endl;
    else
    {
        q1->rear = ((q1->rear - 1) + q1->size) % q1->size;
    }
}
int main()
{
    operations op;
    op.enqueueF(34);
    op.enqueueF(34);
    op.enqueueF(34);
    op.enqueueF(34);
    op.enqueueR(67);
    op.enqueueR(67);
    op.enqueueR(67);
    op.printQueue();

    return 0;
}