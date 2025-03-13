#include<iostream>
#include<stack>
using namespace std;

class Queue{
    private:
      stack<int> s1;
      stack<int> s2;

    public:
     void enqueue(int ele){
       s1.push(ele);
     }

     int dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
               s2.push(s1.top());
               s1.pop();
            }
        }

        //get the front element
        int front=s2.top();
        s2.pop();
        return front;
     }

     //check weather stacks are empty
     bool isEmpty(){
        return (s1.empty() && s2.empty());
     }
};

int main(){
    //make instanc eof our custom queue
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    
    //expected to serverd 1 first as it comes first in queue
    cout<<q.dequeue()<<endl;
}