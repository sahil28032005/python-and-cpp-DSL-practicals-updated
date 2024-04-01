#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class HashMap
{
    Node **arr;

public:
    int size;

    HashMap(int size)
    {
        arr = (Node **)malloc(sizeof(Node) * size);
        this->size = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = NULL;
        }
    }
    void takeInput(int val)
    {
        // Node *n = (Node *)malloc(sizeof(Node));
        // n->data = val;
        Node *n = new Node(val);
        int index = val % size;
        if (arr[index] == NULL)
        {
            arr[index] = n;
            cout << "record inserted..." << endl;
        }
        else
        {
            cout << "collision occured..." << endl;
            Node *temp = arr[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    void search(int data)
    {
        // cout<<"function chya aat";
        if (arr[(data % size)]->data == data)
        {
            cout << "element found at O(1) time compleexity" << endl;
            return;
        }
        else
        {

            Node *temp = arr[data % size];
            while (temp->data != data && temp != NULL)
            {
                temp = temp->next;
            }
            temp->data == data ? cout << "found" : cout << "not found";
        }
    }
};
int main()
{
    HashMap h(10);
    h.takeInput(34);
    h.takeInput(14);
    h.search(14);
    return 0;
}