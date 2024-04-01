#include <iostream>
using namespace std;
class Node
{
public:
    string studentName;
    string studentChoise;
    Node *next;
    Node(string name)
    {
        this->studentName = name;
        this->next = NULL;
    }
};

class SetOperations
{
public:
    Node *takeInput(int noOfstudents);
    void unionOfsets(Node *head1, Node *head2);
    void intersection(Node *head1, Node *head2);
    void differenceOfsets(Node *head1, Node *head2);
    void traverseSets(Node *head);
    int getLength(Node *head);
};

int SetOperations::getLength(Node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}
Node *SetOperations::takeInput(int NoOfstudents)
{
    string name;
    Node *head = NULL;
    Node *p = NULL;
    for (int i = 0; i < NoOfstudents; i++)
    {
        cout << "enter the name of student to add in database" << i + 1 << endl;
        cin >> name;
        Node *student = new Node(name);
        if (i == 0)
        {
            head = student;
            p = head;
        }
        else
        {
            p->next = student;
            p = p->next;
        }
    }
    // cout << getLength(head);
    return head;
}
void SetOperations::traverseSets(Node *head)
{
    while (head != NULL)
    {
        cout << head->studentName << endl;
        head = head->next;
    }
}
void SetOperations::unionOfsets(Node *head1, Node *head2)
{
    int i = 0;
    string arr[getLength(head1) + getLength(head2)];
    // while (head1 != NULL && head2 != NULL)
    // {
    //     if (head1->studentName == head2->studentName)
    //     {
    //         a[i] = head1->studentName;
    //         head1 = head1->next;
    //         head2 = head2->next;
    //         i++;
    //     }
    //     else
    //     {
    //         a[i] = head1->studentName;
    //         head1 = head1->next;
    //         i++;
    //     }
    // }
    // while (head1 != NULL)
    // {
    //     a[i] = head1->studentName;
    //     i++;
    //     head1 = head1->next;
    // }
    // while (head2 != NULL)
    // {
    //     a[i] = head2->studentName;
    //     i++;
    //     head2 = head2->next;
    // }
    // cout << endl;
    i = 0;
    for (Node *a = head2; a != NULL; a = a->next)
    {
        arr[i] = a->studentName;
        i++;
    }
    for (Node *a = head1; a != NULL; a = a->next)
    {
        bool found = false;
        for (Node *b = head2; b != NULL; b = b->next)
        {
            if (a->studentName == b->studentName)
            {
                found = true;
            }
        }
        if (!found)
        {
            arr[i] = a->studentName;
            i++;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << endl;
    }
}
void SetOperations::intersection(Node *head1, Node *head2)
{
    Node *a, *b;
    int i = 0;
    string arr[getLength(head1) + getLength(head2)];
    for (a = head1; a != NULL; a = a->next)
    {
        b = head2;
        while (b != NULL)
        {
            if (a->studentName == b->studentName)
            {
                arr[i] = a->studentName;
                i++;
            }
            b = b->next;
        }
    }
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << endl;
    }
}
void SetOperations::differenceOfsets(Node *head1, Node *head2)
{
    Node *a, *b;

    string arr[getLength(head1) + getLength(head2)];
    int i = 0;
    for (a = head1; a != NULL; a = a->next)
    {
        bool flag = true;
        b = head2;
        while (b != NULL)
        {
            if (a->studentName == b->studentName)
            {
                flag = false;
            }
            b = b->next;
        }
        if (flag)
        {
            arr[i] = a->studentName;
            i++;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    Node *head = NULL;
    Node *head2 = NULL;
    cout << "enter the number of students in list1" << endl;
    int noOfstd = 0;
    int nostd2 = 0;
    cin >> noOfstd;
    cout << "enter the number of students in  list2" << endl;
    cin >> nostd2;
    SetOperations spt;
    head = spt.takeInput(noOfstd);
    head2 = spt.takeInput(nostd2);
    // spt.traverseSets(head);
    // spt.traverseSets(head2);
    spt.unionOfsets(head, head2);
    return 0;
}