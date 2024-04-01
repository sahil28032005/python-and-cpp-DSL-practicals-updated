#include <iostream>
using namespace std;
#include <iomanip>

class Node
{
public:
    int seatNumber;
    bool isBooked;
    Node *prev;
    Node *next;
    string choiseId, data;

    Node(string data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
        // cout << "constructor called" << endl;
    }
};
class CineMaxSystem
{
public:
    Node *head, *tail, *prev;
    void checkAvailableSeats();
    void bookSeat();
    void showCurrentStatus();
    void cancelSeat();
    void createArrangement();
};
void CineMaxSystem::createArrangement()
{
    Node *temp = new Node("available");
    head = temp;
    tail = temp;
    temp->prev = tail;
    temp->next = head;
    temp->isBooked = false;
    temp->seatNumber = 1;
    for (int i = 2; i <= 70; i++)
    {
        temp = new Node("available");
        tail->next = temp;
        temp->prev = tail;
        temp->next = head;
        tail = temp;
        head->prev = tail;
        temp->isBooked = false;
        temp->seatNumber = i;
    }
}
void CineMaxSystem::showCurrentStatus()
{
    Node *p = head;
    int counter = 1;
    do
    {
        cout << " NO" << setw(counter < 10 ? 2 : 1) << counter << " |{" << p->data << "}|";
        if (counter % 7 == 0)
        {
            cout << endl;
        }
        p = p->next;
        counter++;

    } while (p != head);
    // cout<<"asdjhsd"<<(head->prev)->seatNumber << " ";
}

void CineMaxSystem::bookSeat()
{
    Node *head = this->head;
    int seatNum;
checkPoint:
    cout << "enter the seat number which you want to be booked.." << endl;
    cin >> seatNum;
    if (seatNum < 1 || seatNum > 70)
    {
        cout << "invalid seatNumber please enter valid avaliable seat number between 1 to 70" << endl;
        goto checkPoint;
    }
    else
    {
        while (head->seatNumber != seatNum)
        {
            head = head->next;
        }
        if (!(head->isBooked))
        {
            cout << "avaliable for booking..." << endl;
            cout << "enter your unique choiceCode as your identity" << endl;
            cin >> head->choiseId;
            head->isBooked = true;
            head->data = "  booked ";
        }
        else
        {
            cout << "you have entered seat number which is already booked check seat avaliability and book appropriate seat again" << endl;
        }
    }
}
void CineMaxSystem::checkAvailableSeats()
{
    Node *p = head;
    int counter = 1;
    do
    {
        if (p->isBooked)
        {
            // cout << "arriverd";
            p = p->next;
            counter++;
            continue;
        }
        cout << " NO" << setw(counter < 10 ? 2 : 1) << counter << " |{" << p->data << "}|";
        if (counter % 7 == 0)
        {
            cout << endl;
        }
        p = p->next;
        counter++;

    } while (p != head);
}
void CineMaxSystem::cancelSeat()
{
    int seatNum;
    string key;
    Node *p = head;
    cout << "enter seat number which you want to cancel..." << endl;
    cin >> seatNum;
    while (p->seatNumber != seatNum)
    {
        p = p->next;
    }
    if (!p->isBooked)
    {
        cout << "you entered seat number which is not booked yet to cancel enter right seat nummber..." << endl;
        return;
    }
    cout << "enter your unique choisecode for authentication..." << endl;
    cin >> key;
    if ((p->choiseId) == key)
    {
        cout << "key matched..." << endl;
        p->data = "available";
        p->choiseId = "";
        p->isBooked = false;
        cout << "your seat has been cancelled...." << endl;
    }
}
int main()
{
    CineMaxSystem system;
    bool looper = true;
    int choise;
    system.createArrangement();
    while (looper)
    {
        cout << ".........................WELCOME TO CINEMAX TICKET BOOKING SYSTEM...................." << endl;
        cout << "CHOOSE FROM THE OPTIONS BELOW\n1)CHECK AVALIABILITY OF SEATS\n2)CHECK CURRENT STATUS OF ALL BOOKINGS\n3)BOOK MY SEAT\n4)CANCEL MY SEAT" << endl;
        cout << "enter yout choise" << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            system.checkAvailableSeats();
            break;
        case 2:
            system.showCurrentStatus();
            break;
        case 3:
            system.bookSeat();
            break;
        case 4:
            system.cancelSeat();
            break;
        case 5:
            cout << "exiting....";
            looper = false;
            break;
        default:
            cout << "choose correct option" << endl;
        }
    }

    return 0;
}