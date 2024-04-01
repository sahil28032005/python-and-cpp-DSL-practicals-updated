#include <iostream>
using namespace std;
template <class t>
class Stack
{
public:
    int size, top;
    t *arr;
    Stack(int size)
    {
        top = -1;
        this->size = size;
    }
};
class StackOperations
{
private:
public:
    Stack<char> *s;
    void createStack(int size);
    void pushIntoStack(char element);
    void popFromStack();
    bool isEmpty();
    bool isFull();
    void viaSualizeStack();
    bool isWellParenthesized(string expression);
};
void StackOperations::createStack(int size)
{
    s = new Stack<char>(size);
    s->arr = new char[s->size]; // i thin this will allocate dynamic mempory another approach using malloc
}
bool StackOperations::isEmpty()
{
    return s->top == -1 ? true : false;
}
bool StackOperations::isFull()
{
    return s->top == s->size - 1 ? true : false;
}
void StackOperations::pushIntoStack(char element)
{
    if (isFull())
    {
        cout << "stack overflow!" << endl;
        return;
    }
    s->top++;
    s->arr[s->top] = element;
}
void StackOperations::viaSualizeStack()
{
    for (int i = 0; i <= s->top; i++)
    {
        cout << "|" << s->arr[i] << "|" << endl;
    }
}
void StackOperations::popFromStack()
{
    if (isEmpty())
    {
        cout << "stack underFlow!" << endl;
        return;
    }
    s->top--;
}
bool ::StackOperations::isWellParenthesized(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            pushIntoStack(exp[i]);
        }
        else if (((s->top) >= 0) && (s->arr[s->top] == '(' && exp[i] == ')' || s->arr[s->top] == '[' && exp[i] == ']' || s->arr[s->top] == '{' && exp[i] == '}'))
        {
            popFromStack();
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            // pushIntoStack(exp[i]); this can't be prefered because we only pushing opening brackets but it worked!
            cout << "not well parenthesized<<endl";
            
            return false;
        }
    }
    if (isEmpty())
    {
        cout << "your expression is well parenthesized..." << endl;
        return true;
    }
    else
    {
        cout << "not well parenthesized...." << endl;
        return false;
    }
}

int main()
{
    StackOperations stp;
    stp.createStack(12);
    // stp.pushIntoStack('c');
    // stp.pushIntoStack('d');
    // stp.pushIntoStack('g');
    stp.isWellParenthesized("(})");
    stp.viaSualizeStack();

    return 0;
}