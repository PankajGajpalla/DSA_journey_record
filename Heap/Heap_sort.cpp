#include<iostream>
using namespace std;

// Arrays in C++ are always passed by reference implicitly (as pointers), so modifications inside a function directly affect the original array. That’s why heapify() changes arr without using &.

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2 +1;
    int right = i*2 +2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]> arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}


void heap_sort(int arr[], int n){
    
    for(int i=n/2 -1; i>=0; i--){
        heapify(arr, n, i);
    }


    int t = n-1;

    while(t>0){
        swap(arr[0], arr[t]);
        
        heapify(arr, t, 0);
        t--;
    }
    return;
}

void print(int arr[], int n){
    // int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    
    int arr[] = {54, 53, 55, 52, 50, 3, 100, 51};
    int n = sizeof(arr)/sizeof(arr[0]);

    
    heap_sort(arr, n);

    print(arr, n);

    return 0;
}