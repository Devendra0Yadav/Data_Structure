#include <iostream>

using namespace std;
template <class T>
class Node
{
public:
    Node(T theData, Node<T> *theLink) : data(theData), link(theLink) {}
    Node<T> *getLink() const { return link; }
    const T getData() const { return data; }
    void setData(const T &theData) { data = theData; }
    void setLink(Node<T> *pointer) { link = pointer; }

private:
    T data;
    Node<T> *link;
};
template <class T>
class Stack
{
public:
    Stack();
    Stack(const Stack<T> &aStack);
    Stack<T> &operator=(const Stack<T> &rightSide);
    virtual ~Stack();
    void push(T stackFrame);
    T pop();
    bool isEmpty() const;

private:
    Node<T> *top;
};
template <class T>
Stack<T>::Stack() : top(nullptr) {}
template <class T>
Stack<T>::Stack(const Stack<T> &aStack)
{
    if (aStack.isEmpty())
    {
        top = nullptr;
    }
    else
    {
        Node<T> *temp = aStack.top;
        Node<T> *end;
        end = new Node<T>(temp->getData(), nullptr);
        top = end;
        //First node created and filled with data.
        //New nodes are now added after this first node.
        temp = temp->getLink(); //move temp to second node
        // or nullptr if there is no second node.
        while (temp != nullptr)
        {
            end->setLink(new Node<T>(temp->getData(), nullptr));
            temp = temp->getData();
            end = end->getLink();
        }
    }
}
template <class T>
void Stack<T>::push(T stackFrame)
{
    top = new Node<T>(stackFrame, top);
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rightSide)
{
    if (top == rightSide.top) // if two stack are the same
        return *this;
    else
    { //send left side back to freestore
        T next;
        while (!isEmpty())
        {
            next = pop(); //remove calls delete.
        }
    }
    if (rightSide.isEmpty())
    {
        top = nullptr;
        return *this;
    }
    else
    {
        Node<T> *temp = rightSide.top; //temp moves through
        // the node from front top bottom of rightSide.
        Node<T> *end; //points to end of the left-side stack.
        end = new Node<T>(temp->getData(), nullptr);
        top = end;
        //First node created and filled with data.
        //New nodes are now added After this first node.
        temp = temp->getLink(); //Move temp to second
        // or set to nullptr if there is no second node
        while (temp != nullptr)
        {
            end->setLink(new Node<T>(temp->getLink(), nullptr));
            temp = temp->getLink();
            end = end->getLink();
        }
        //end->link == nullptr;
        return *this;
    }
}
template <class T>
Stack<T>::~Stack()
{
    T next;
    while (!isEmpty())
    {
        next = pop(); //pop calls delete
    }
}
template <class T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}
template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Error: popping an empty stack.\n";
        exit(1);
    }
    T result = top->getData();
    Node<T> *discard;
    discard = top;
    top = top->getLink();
    delete discard;
    return result;
}

int main()
{
    char next, ans;
    do
    {
        Stack<char> s;
        cout << "\nEnter a line of text:\n";
        cin.get(next);
        while (next != '\n')
        {
            s.push(next);
            cin.get(next);
        }
        cout << "Written backward that is:\n";
        while (!s.isEmpty())
        {
            cout << s.pop();
        }
        cout << endl;
        cout << "Again?(y/n):";
        cin >> ans;
        cin.ignore(10000, '\n');

    } while (ans != 'n' && ans != 'N');
    return 0;
}
/*


Enter a line of text:
This Cali
Written backward that is:
ilaC sihT
Again?(y/n):y

Enter a line of text:
Generic Programming in C++
Written backward that is:
++C ni gnimmargorP cireneG
Again?(y/n):n


*/