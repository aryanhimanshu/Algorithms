#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node*next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};


class Stack
{
    Node*head;
    int curSize;

    public:

    Stack()
    {
        head=NULL;
        curSize=0;
    }

    void push(int d)
    {
        Node*temp = new Node(d);
        temp->next = head;
        head = temp;
        curSize++;
    }

    void pop()
    {
        Node*newHead = head->next;
        delete head;
        head = newHead;
        curSize--;
    }

    bool isEmpty()
    {
        return curSize==0?true:false;
    }

    int top()
    {
        if(isEmpty())
        {
            return head->data;
        }
        else
        {
            return -1;
        }
    }

    void print()
    {
        Node*temp = head;
        while(temp!=NULL)
        {

            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }


    ~Stack()
    {
        Node *temp = head;
        cout<<"Deleting Stack"<<endl;
        while(temp!=NULL)
        {
            Node*next = temp->next;
            delete temp;
            temp = next;
        }
    }

    friend ostream operator<<(ostream&os, const Stack&s);
};

ostream operator<<(ostream&os, const Stack&s)
{
    Node*temp = s.head;
        while(temp!=NULL)
        {

            os<<temp->data<<endl;
            temp=temp->next;
        }


    return os;
}



int main()
{

    Stack *s = new Stack();

    s->push(1);
    s->push(3);
    s->push(5);
    s->pop();

    s->print();

    delete s;

    return 0;
};

