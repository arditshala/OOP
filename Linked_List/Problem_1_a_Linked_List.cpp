#include <iostream>

using namespace std;

class StackUnderFlowException
{
public:
    StackUnderFlowException()
    {
        cout << "Stack underflow" << endl;
    }
};

template <typename T>
class stack{
public:
    stack();
    stack(int new_size);
    void push(T);
    void pop(T &);
    bool isEmpty(void);

private:
    struct node{
    node(){  next = NULL; }
    T data;
    node* next;
 }*top;

};

template <typename T>
stack<T>::stack(int new_size)
{
    top = new_size;
}


template <typename T>
stack<T>::stack()
{
    top = NULL;
}



template <typename T>
void stack<T>::push(T x)
{
    node* newNode = new node;
    newNode->data = x;

    if (top != NULL)
    {
        newNode->next = top;
        top = newNode;
    }
    else
    {
        newNode->next = NULL;
        top = newNode;
    }
}


template <typename T>
void stack<T>::pop(T &x){
    if (isEmpty())
    {
        throw new StackUnderFlowException();
    }
    else
    {
        x = top->data;
        node* temp = top;
        top = top->next;
        delete temp;
        temp = NULL;
    }
}


template <typename T>
bool stack<T>::isEmpty(void)
{
    return top == NULL;
}


int main(){

    stack<int> s;

    try
    {
        if(s.isEmpty())
        {
            cout << "Stack is empty" << endl;
        }

        s.push(100);
        s.push(200);

        int x;

        for (int i = 1; i<=5; i++)
        {
            s.pop(x);
            cout << x << endl;
        }
    }

    catch(...)
    {
        cout << "Some exception occured" << endl;
    }
}
