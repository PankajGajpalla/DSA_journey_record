#include<iostream>
using namespace std;

void recursive_bubble_sort(int arr[], int n){
    if (n==1) return;

    for(int i=0; i<=n-2; i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    recursive_bubble_sort(arr, n-1);
}

int main()
{
    int arr[] = {4,2,5,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    recursive_bubble_sort(arr, size);
    
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}