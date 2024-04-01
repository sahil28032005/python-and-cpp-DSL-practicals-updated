#include <iostream>
using namespace std;
class queue
{
public:
    int size;
    int front, rear;
    string *arr;
    queue(int size)
    {
        // cout<<"size: "<<size<<endl;
        this->front = -1;
        this->rear = -1;
        this->size = size;
        this->arr = new string[size];
    }
    ~queue(){
        delete []arr;
    }
};
class queueOperations
{
public:
    queue *q = new queue(10);
    void addJob(string job);
    void removeJob();
    void visualizeJobQueue() const;
    bool isFull() const;
    bool isEmpty() const;
    void dequeue();
};
void queueOperations::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        q->front++;
    }
}
void queueOperations::addJob(string job)
{
    if (isFull())
    {
        cout << "queue full delete some jobs" << endl;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front++;
        q->arr[q->rear + 1] = job;
        q->rear++;
        cout << "job added" << endl;
    } 
    else
    {
        q->arr[q->rear + 1] = job;
        q->rear++;
        cout << "job added" << endl;
    }
}
void queueOperations::visualizeJobQueue() const
{
    for (int i = q->front; i < q->size; i++)
    {
        cout << "|" << q->arr[i] << "|"
             << " ";
    }
    cout << endl;
}
bool queueOperations::isFull() const
{
    return q->rear == q->size - 1 && q->front == 0 ? true : false;
}
bool queueOperations::isEmpty() const
{
    return q->front == -1 && q->rear == -1 || q->front > q->rear ? true : false;
}
int main()
{
    queueOperations qop;
    qop.addJob("print document");
    qop.addJob("request drivers");
    qop.addJob("request system call");
    qop.visualizeJobQueue();
    qop.dequeue();
    qop.dequeue();
    qop.dequeue();
    qop.dequeue();
    qop.dequeue();
    qop.dequeue();
    qop.dequeue();
    qop.visualizeJobQueue();
    return 0;
}