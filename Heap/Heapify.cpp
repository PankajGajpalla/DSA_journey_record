#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    
    int largest = i;
    int left = i*2;
    int right = i*2 + 1;

    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        // swap kara hai array ke value ko but largest is the index where it is 
        heapify(arr, n, largest);
    }else{
        return;
    }
}

// the formula for leaf nodes in a heap is from n/2 +1 till...  n and as the leaf node itself is a heap dont require heapify
// so the left out from 1 to n/2 we need to do heapify 
int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i= n/2; i>0; i--){
        heapify(arr, n, i);
    }

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}