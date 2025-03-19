#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size =  0;
    }

    void insert(int val){
        size = size+1;
        int index = size;

        arr[index] = val;

        while(index>1){
            int parrent = index/2;
            if(arr[parrent] < arr[index]){
                swap(arr[parrent], arr[index]);
                index = parrent;
            }else{
                return;
            }
        }
    }

    void deleteRootNode(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i=1;
        while(i<size){
            int leftIndex = i*2;
            int rightIndex = i*2 +1;

            if(leftIndex < size && arr[leftIndex]> arr[i]){
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }else if(rightIndex <size && arr[rightIndex] > arr[i]){
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


// time complexity in heap for insertion and deletion is o(log n) for both 

int main(){
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(3);
    h.insert(7);

    h.print();

    h.deleteRootNode();
    h.print();

    return 0;
}