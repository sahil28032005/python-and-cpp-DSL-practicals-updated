#include <iostream>
using namespace std;
class Queue
{
public:
    int front, rear, *arr, size;
    Queue(int size)
    {
        front = -1;
        rear = -1;
        arr = (int *)malloc(sizeof(int) * size);
        this->size = size;
    }
    bool isEmpty() const;
    bool isFull() const;
};

bool Queue::isEmpty() const
{
    return front == rear ? true : false;
    // return front == -1 && rear == -1 ? true : false;
}
bool Queue::isFull() const
{
    return front == (rear + 1) % size ? true : false;
}
class PizzaSalse
{
private:
    Queue *q = new Queue(6);

public:
    void printQueue() const;
    bool deliverPizza()
    {
        if (q->isEmpty())
        {
            cout << "no orders to deliver please order some items" << endl;
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % q->size;
            cout << "delivered and current front is " << q->front << endl;
        }
    }
    bool orderPizza(int type)
    {
        if (q->isFull())
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else
        {
            if (q->rear == -1)
            {
                q->rear = 0;
                q->front = 0;
                q->arr[q->rear] = type;
                cout << "added current rear is " << q->rear << "current front is " << q->front << endl;
                return true;
            }
            else
            {
                q->rear = q->rear + 1 % q->size;
                q->arr[q->rear] = type;
                cout << "added current rear is " << q->rear << "current front is " << q->front << endl;
                return true;
            }
        }
    }
};
void PizzaSalse::printQueue() const
{
    for (int i = q->front; i <= q->rear; i++)
    {
        cout << q->arr[i] << " ";
    }
}
int main()
{
    
    return 0;
}