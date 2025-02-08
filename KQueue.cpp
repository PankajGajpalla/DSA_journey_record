#include<iostream>
using namespace std;

class KQueue{
    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;

    public:
    KQueue(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        freespot = 0;

        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
    }

    void enqueue(int data, int qn){
        if(freespot == -1){
            return;
        }

        int index = freespot;

        freespot = next[index];

        if(front[qn-1] == -1){
            front[qn-1] = index;
        }else{
            next[rear[qn-1]] = index;
        }

        next[index] = -1;

        rear[qn-1] = index;

        arr[index] = data;
    }

    int dequeue(int qn){
         if(front[qn-1] == -1){
            return -1;
         }

         int index = front[qn-1];

         front[qn-1] = next[index];

         next[index] = freespot;

         freespot = index;

         return arr[index];
    }

    int samne(int qn){
        return arr[front[qn-1]];
    }
};

int main(){
    KQueue q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(11,1);
    q.enqueue(5,2);
    q.enqueue(21,3);
    q.enqueue(6,2);
    q.enqueue(12,1);
    q.enqueue(22,3);

    cout<<q.dequeue(1)<<endl;
    cout<<q.samne(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;



    return 0;
}
