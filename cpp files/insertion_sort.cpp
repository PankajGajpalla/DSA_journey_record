#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j = i;
        while(j>0 && arr[j -1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, size);
    return 0;
}