#include <iostream>
using namespace std;
class Stack
{
public:
    int top;
    int size;
    char *arr = (char *)malloc(sizeof(char) * size);
    Stack(char size)
    {
        this->top = -1;
        this->size = size;
    }
};
class stackOperations
{
public:
    string resultant;
    Stack *ref;
    void createStack(int size);
    bool isEmpty();
    bool isFull();
    void push(char ch);
    char pop();
    bool isOperator(char ch);
    string returnPostfix(string expr);
    int precedence(char c);
    void viaSualizeStack();
};
int stackOperations::precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '(' || ch == ')')
    {
        return 0;
    }
}
void stackOperations::createStack(int size)
{
    {
        Stack *s = new Stack(size);
        this->ref = s;
    }
}
bool stackOperations::isEmpty()
{
    {
        return ref->top == -1 ? true : false;
    }
}
bool stackOperations::isFull()
{
    return ref->top == ref->size - 1 ? true : false;
}
void stackOperations::push(char ch)
{
    if (isFull())
    {
        cout << "stack overflow!" << endl;
        return;
    }
    else
    {
        ref->top++;
        ref->arr[ref->top] = ch;
    }
}
char stackOperations::pop()
{
    if (isEmpty())
    {
        cout << "stacl underflow!" << endl;
        return 'f';
    }
    else
    {
        char c = ref->arr[ref->top];
        ref->top--;
        return c;
    }
}
bool stackOperations::isOperator(char ch)
{

    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch > '0' && ch <= '9')
    {
        return true;
    }
    return false;
}
void stackOperations::viaSualizeStack()
{
    for (int i = 0; i <= ref->top; i++)
    {
        cout << "|" << ref->arr[i] << "|" << endl;
    }
}

string stackOperations::returnPostfix(string expr) // a+b+c+d*45
{

    cout << expr.length() << endl;
    int i = 0, j = 0;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(')
        {
            push(expr[i]);
            continue;
        }
        else if (expr[i] == ')')
        {
            while (ref->arr[ref->top] != '(')
            {
                char c = pop();
                if (c != '(')
                {
                    resultant += c;
                }
            }
            pop();
            continue;
        }
        if ((isOperator(expr[i])))
        {
            resultant += expr[i];
            continue;
        }

        if (isEmpty())
        {
            push(expr[i]);
        }
        else
        {
            if (precedence(expr[i]) > precedence(ref->arr[ref->top]))
            {
                push(expr[i]);
            }
            else
            {
                while (precedence(expr[i]) <= precedence(ref->arr[ref->top]) && !isEmpty())
                {
                    resultant += pop();
                }
                push(expr[i]);
            }
        }
    }
    if (isEmpty())
    {
    }
    else
    {
        while (ref->top != -1)
        {
            resultant += pop();
        }
    }

    return resultant;
}
int main()
{
    stackOperations stp;
    stp.createStack(4);
    string res = stp.returnPostfix("(a+b)*(c+d)");
    // string res = stp.returnPostfix("a + b * c");
    // string res = stp.returnPostfix("(a + b) * c");
    // string res = stp.returnPostfix("(a + b) * c");
    // string res = stp.returnPostfix("");

    // stp.viaSualizeStack();
    cout << res << endl;
    return 0;
}