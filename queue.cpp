/*Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.*/

#include <iostream>
using namespace std;

class JobQueue
{
public:
    const static int maxSize = 10;
    int rear = -1;
    int front = -1;
    int size;
    int jobList[maxSize];

    void addJob(int jobNumber)
    {
        if (rear == maxSize - 1)
        {
            cout << "Overflow!!!";
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            jobList[rear] = jobNumber;
        }
        else
        {
            rear++;
            jobList[rear] = jobNumber;
        }
    }

    void deleteJob()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Underflow!!! [Queue is Empty]" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            cout << jobList[front] << endl;
            front = (front + 1) % maxSize;
        }
    }

    void displayQueue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Queue Contains:";
            for (int i = front; i <= rear; i++)
            {
                cout << jobList[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    JobQueue jobQueue;
    int userChoice, jobNumber;

    do
    {
        cout << "Enter choice from options given below" << endl;
        cout << "Note: (Job number should be in integer type)" << endl;
        cout << "1. To Add Job" << endl;
        cout << "2. To Delete Job" << endl;
        cout << "3. To Display Queue" << endl;
        cout << "4. Exit" << endl;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            cout << "Enter Job Number:" << endl;
            cin >> jobNumber;
            jobQueue.addJob(jobNumber);
            break;
        case 2:
            cout << "The Deleted Job Number:";
            jobQueue.deleteJob();
            break;
        case 3:
            jobQueue.displayQueue();
            break;
        case 4:
            break;
        default:
            cout << "Enter valid option:";
            break;
        }
    } while (userChoice != 4);

    return 0;
}

