#include <iostream>
using namespace std;
class Heap
{
public:
    int size;
    int index, *arr;
    Heap(int size)
    {
        arr = new int[size];
        index = 0;
    }
    void insertIntoHeap(int data)
    {
        if (index < size)
        {
            arr[index] = data;
            int temp = index;
            index++;
            while (temp > 0)
            {
                int parent = (temp - 1) / 2;
                cout << "parent " << parent << endl;
                if (!(arr[parent] > arr[temp]))
                {
                    // not satisfied max heap property
                    swap(arr[parent], arr[temp]);
                    temp = parent;
                }
                else
                {
                    return;
                }
            }
        }
        else
        {
            cout << "heap is full remove some elements" << endl;
        }
    }
    void printHeap()
    {
        for (int x = 0; x < index; x++)
        {
            cout << arr[x] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int data, choise;
    Heap *h = new Heap(56);
    while (1)
    {
        cout << "ENTER YOUR CHOISE!" << endl;
        cout << "1)INSERT MARKS HEAP\n"
             << "2)DISPLAY HEAP\n"
             << "3)DISPLAY MIN  MARKS\n"
             << "4)DISPLAY MAX MARKS\n"
             << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Enter data to insert\n"
                 << endl;
            cin >> data;
            while (data != -1)
            {

                h->insertIntoHeap(data);
                cout << "enter next element otherwise press -1 " << endl;
                cin >> data;
            }
            break;

        case 2:
            cout << "DISPLAYING DATA:" << endl;
            h->printHeap();
            break;
        case 3:
            cout << "MIN MARKS: " << h->arr[h->index - 1] << endl;
            break;
        case 4:
            cout << "MAX MARKS: " << h->arr[0] << endl;
            break;
        }
    }

    return 0;
}