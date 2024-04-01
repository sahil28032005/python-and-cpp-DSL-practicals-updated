#include<iostream>
using namespace std;
const int N=10;

class priorityQ
{
  int front, rear;
  int data_element[N];
  int priority[N];
  
  public:
  priorityQ()
  {
      front=rear=-1;
  }
  void enqueue(int x,int pr)
  {
      if(rear==N-1)
      {
          cout<<"Queue is Full!"<<endl;
          return;
      }
      else if(front==-1 && rear==-1)
      {
          front=rear=0;
          data_element[rear]=x;
          priority[rear]=pr;
      }
      else
      {
          int i;
          for(i=rear;i>=front;i--)
          {
              if(pr>=priority[i])
              {
                  data_element[i+1]=data_element[i];
                  priority[i+1]=priority[i];
              }
              else
              {
                  break;
              }
          }
          data_element[i+1]=x;
          priority[i+1]=pr;
          rear++;
          cout<<"Element Enquequed"<<endl;
      }
  }
  void dequeue()
  {
      int temp,temp1;
      if(front==-1 && rear==-1)
      {
          cout<<"Queue is Empty!"<<endl;
          return;
      }
      else if(front==rear)
      {
          temp=data_element[front];
          temp1=priority[front];
          front=rear=-1;
      }
      else
      {
          temp=data_element[front];
          temp1=priority[front];
          front++;
      }
      cout<<"\n Element:"<<temp<<" with priority :"<<temp1<<" dequequed"<<endl;
  }
  void display()
  {
      if(front==-1 && rear==-1)
      {
          cout<<"Queue is empty!"<<endl;
      }
      else
      {
          cout<<"(Element Priority):"<<endl;
          for(int i=front;i<=rear;i++)
          {
              cout<<"("<<data_element[i]<<","<<priority[i]<<")"<<endl;
          }
      }
  }
  
};
int main()
{
    priorityQ obj;
    int ch;
    int x,pr;
    do
    {
        cout<<"\nEnter option no. to perform operation on Priority Queue(Ascending):"<<endl;
        cout<<"Enter 0 for exit"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue "<<endl;
        cout<<"3. Display"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 0:
            break;
            case 1:
                cout<<"Enter Element:"<<endl;
                cin>>x;
                cout<<"Enter Priority:"<<endl;
                cin>>pr;
                obj.enqueue(x,pr);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                obj.display();
                break;
            default:
                cout<<"Enter the valid option!"<<endl;
                break;
        }
    }while(ch!=0);
    return 0;
}