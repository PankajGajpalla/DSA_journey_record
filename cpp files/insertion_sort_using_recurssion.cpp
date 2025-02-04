#include<iostream>
using namespace std;

void recursive_insertion_sort(int arr[], int n, int i)
{
    if(i ==n) return;

    int left = i;
    while(left>0 && arr[left]<arr[left-1]){
        int temp = arr[left];
        arr[left] = arr[left-1];
        arr[left-1] = temp;
        left--;
    }

    recursive_insertion_sort(arr,n, i+1);
}
int main()
{
    int arr[] = {5,2,1,4,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    recursive_insertion_sort(arr, size, 0);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}