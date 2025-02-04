#include<iostream>
using namespace std;
class Node{
    public:

    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

bool iscircle(Node* head){
    if(head == NULL){
        return true;
    }
    if(head->next == NULL){
        return true;
    }
    
    Node* temp = head->next;
    while(temp != head && temp != NULL){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    if(temp == NULL){
        return false;
    }
}

Node* flowdetect(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast-> next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow) return slow;

    }
    return NULL;
}

Node* getstarting(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* intersection = flowdetect(head);
    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}