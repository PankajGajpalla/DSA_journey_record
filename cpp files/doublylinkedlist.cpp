#include<iostream>
using namespace std;


class Node{
    
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;

        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<< " memory is freed " << val <<endl;
    }

};

//traversing  a linked list
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp =  temp->next;
    }
    cout << endl;
}

//gives length of linked list
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail,int position, int data){
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
    NodeToInsert->prev = temp;
    temp->next = NodeToInsert;
    temp->next->prev = NodeToInsert;
    
}

void deleteNode(int position , Node* &head, Node* &tail){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if(curr->next == NULL){
            prev->next = NULL;
            tail = prev;
            curr->prev = NULL;
            delete curr;
            return;
        }
 
        prev->next = curr->next;
        curr -> prev = NULL;
        curr->next->prev = prev;
        curr -> next = NULL;

        delete curr;   
    }

}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head, 11);
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 13);
    print(head);

    insertAtTail(tail, 9);
    print(head);

    insertAtPosition(head, tail, 3, 50);
    print(head);
 
    insertAtPosition(head, tail, 1, 100);
    print(head);
    
    int n = getLength(head);
    insertAtPosition(head, tail, n+1, 1);
    print(head);

    // insertAtHead(head, 100);
    deleteNode(1, head, tail);
    print(head);

    
    deleteNode(4, head, tail);
    print(head);

    
    deleteNode(6, head, tail);
    print(head);

    cout << "head " << head->data <<endl;
    
    cout << "tail " << tail-> data << endl;
    return 0;
}