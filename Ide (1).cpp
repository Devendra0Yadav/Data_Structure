#include <iostream>
using namespace std;

class LinkedList{
    class Node{
    public:
    int data;
    Node *next;
    Node(){
        
    }
    Node(int x){
        data=x;
        next=NULL;
    }
    };
    private:
    int len=0;
    Node *root=NULL;
    Node *lastP;
    Node *firstP;
    public:
    LinkedList(){
        
    }
    void addLast(int d){
        if(root==NULL){
            root = new Node(d);
            lastP = root;
            len++;
        }
        else{
            // if we use this below code to add element at last then time complexcity is much high.
            // Node *temp=root;
            // while(temp->next!=NULL){
            //     temp=temp->next;
            // }
            // temp->next= new Node(d);
            
            // but this below code is much more efficient than former one. because 
            // in each addition of new node takes only constant time i.e O(1);
            Node *temp= new Node(d);
            lastP->next= temp;
            lastP = temp;
            len++;
            
        }
    }
    
    void addFirst(int d){
        if(root==NULL){
            root = new Node(d);
            firstP = root;
            len++;
        }
        else{
            Node *temp= new Node(d);
            temp->next = root;
            root=temp;
            len++;
        }
    }
    
    void display(){
        if(root==NULL){
            cout<<"\nEmpty List.\n";
            return ;
        }
        cout<<"\nThe length of linked list is "<<len<<endl;
        int k =0;
        
        Node *p=root;
        while(p!=NULL){
            cout<<p->data<<",\n ";
            p=p->next;
            k++;
        }
    }
    
};

int main() {
	LinkedList ll ;
	ll.display();
	ll.addLast(4);
	ll.addLast(5);
	ll.addLast(9);
	ll.addFirst(45);
	ll.addFirst(3);
	ll.addLast(455);
	for(int i=0;i<20;i++){
	    if(i%2==0){
	        ll.addLast(117);
	    }
	    else{
	        ll.addFirst(113);
	    }
	}
	ll.display();
	return 0;
}
