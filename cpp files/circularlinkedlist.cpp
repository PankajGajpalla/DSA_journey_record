#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;

    // constructor 
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<< "memory freed from value : "<< value <<endl;

    }
};

void insertNode(Node* &tail, int element, int data){
    //assuming that the element is present in the last

    //empty list
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }

        //element found -> curr is representing eleent wala node
        Node* temp = new Node(data);
        temp ->next = curr->next;
        curr->next = temp;
        
    }
}

void print(Node* tail){ // imp by value pass kiya hai to dikat nhi aega
    Node* temp = tail;
    // cout<< tail->data <<" ";
    do{
        cout<< tail -> data<< " ";
        tail = tail -> next;
    }while(tail != temp);
    cout<<endl;
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail == NULL){
        cout<< "list is already empty , check again" <<endl;
        return;
    }
    else{
        //non - empty

        Node* prev = tail;
        Node* curr = tail->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        //1 Nude linked list
        prev->next = curr->next;
        if(curr == prev){
            tail = NULL;
        }

        //Node linked list
        if(tail == curr){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}


int main(){
    Node* tail = NULL;

    //empty list me insert krre hai
    insertNode(tail, 5, 3);
    print(tail);
    
    insertNode(tail, 3, 4);
    print(tail);
    
    insertNode(tail, 4, 5);
    print(tail);
    
    insertNode(tail, 5, 6);
    // cout<< tail->data <<endl;
    print(tail);
    
    insertNode(tail, 4, 1);
    print(tail);
    
    insertNode(tail, 3, 2);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    deleteNode(tail, 6);
    print(tail);
    deleteNode(tail, 4);
    print(tail);
    deleteNode(tail, 2);
    deleteNode(tail, 3);
    print(tail);
    // deleteNode(tail, );
    // print(tail);
    

    return 0;
}