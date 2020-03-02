#include <iostream>
#include <string>

using namespace std;

class list
{
    class Node
    {
    public:
        Node *prev;
        int data;
        Node *next;

    public:
        Node(int data)
        {
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }
        Node(){};
    };
    Node *head = nullptr;
    Node *lp = nullptr;
    unsigned int len = 0;

public:
    list() {}

    void addFirst(int d)
    {
        if (head == nullptr && lp == nullptr)
        {
            Node *p = new Node(d);
            head = p;
            lp = head;
            len++;
        }
        else
        {
            Node *temp = new Node(d);
            temp->next = head;
            head->prev = temp;
            temp->prev = nullptr;
            head = temp;
            len++;
        }
    }
    void addLast(int d)
    {
        if (lp == nullptr && head == nullptr)
        {
            head = lp = new Node(d);
            len++;
        }
        else
        {
            Node *temp = new Node(d);
            lp->next = temp;
            temp->prev = lp;
            lp = temp;
            len++;
        }
    }
    unsigned int size()
    {
        unsigned int k = len;
        if (k < 0)
        {
            return 0;
        }
        else
            return k;
    }
    bool isEmpty()
    {
        return this->size() == 0;
    }
    int getFirst()
    {
        try
        {
            if (head != nullptr)
            {
                return head->data;
            }
            else
            {
                string exp = "NoSuchElementException";
                throw exp;
            }
        }
        catch (string exp)
        {
            cout << exp;
        }
        return -1;
    }
    int getLast()
    {
        try
        {
            if (lp != nullptr)
            {
                return lp->data;
            }
            else
            {
                string exp = "NoSuchElementException";
                throw exp;
            }
        }
        catch (string exp)
        {
            cout << exp << endl;
        }
        return -1;
    }
    int removeFirst()
    {
        if (head == nullptr && lp == nullptr)
        {
            return -1;
        }
        else
        {
            Node *p = head;
            head = p->next;
            len--;
            int element = p->data;
            delete p;
            return element;
        }
    }
    int removeLast()
    {
        if (head == nullptr)
        {
            return -1;
        }
        else
        {
            if (head->next == nullptr)
            {
                delete head;
                head = lp = nullptr;
                len = 0;
                return -1;
            }
            Node *r = lp;
            lp = r->prev;
            lp->next = nullptr;
            int element = r->data;
            len--;
            delete r;

            return element;
        }
    }

    void printNodes()
    {

        Node *p = head;
        if (p == nullptr)
        {
            cout << "\nList Empty.";
            return;
        }
        else
        {
            while (p != nullptr)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << "\n";
        }
    }
};

int main()
{
    list l;
    if (l.isEmpty())
    {
        cout << "\nYes, This List is empty.\n";
    }
    else
    {
        cout << "\nList is not empty.\n";
    }
    cout << l.getFirst() << endl;
    l.addFirst(98);
    l.addFirst(2);
    l.addFirst(3);
    l.addLast(4);
    l.removeFirst();
    l.addLast(5);
    l.removeFirst();
    cout << "\nLast Element " << l.getLast() << endl; // 98 4 5 76
    cout << l.getFirst() << endl;
    if (l.isEmpty())
    {
        cout << "\nYes, This List is empty.\n";
    }
    else
    {
        cout << "\nList is not empty.\n";
    }
    cout << l.size() << endl;
    cout << "\nLast Element " << l.getLast() << endl;
    cout << "\nThe first element is " << l.removeFirst() << endl;
    l.printNodes();
    l.addLast(76);
    l.printNodes();
    l.addFirst(8);
    l.removeLast();
    cout << l.size() << endl;
    l.printNodes();
    l.removeFirst();
    cout << l.size() << endl;
    l.removeLast();
    cout << l.size() << endl;
    l.removeFirst();
    cout << l.size() << endl;
    cout << l.size() << endl;
    l.printNodes();
}