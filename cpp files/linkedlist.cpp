#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor;
    Node(int data){
        this->data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this->data; // ase hi dikhane ke liye no need

        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d){

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp; 
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data){
    
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* NodeToInsert = new Node(data);
    NodeToInsert->next = temp->next;
    temp->next = NodeToInsert;
}

void deleteNode(Node* &head,Node* &tail, int position){

    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == NULL){
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node* &head){
    
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data<< " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){

    // Node node1;
    // node1.data = 4;
    // cout<<node1.data<<endl;
    // cout << node1.next <<endl;
    
    // Node* node1 = new Node();
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    //after making constructor
    Node* node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    // print(node1);
    print(head);

    insertAtHead(head, 12);
    print(head);
    
    insertAtHead(head, 15);
    print(head);

    insertAtTail(tail, 9);
    insertAtTail(tail, 7);
    insertAtPosition(tail, head, 3, 11);
    print(head);

    insertAtPosition(tail, head, 1, 16);
    print(head);

    insertAtPosition(tail, head, 8, 5);
    print(head);

    deleteNode(head,tail, 5);
    print(head);

    deleteNode(head,tail, 1);
    print(head);
   
    deleteNode(head,tail, 6);
    print(head);

    cout << "head " << head -> data <<endl;
    cout << "tail " << tail -> data <<endl; 
    return 0;
}