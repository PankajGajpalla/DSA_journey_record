#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
    
// void bubble_sort(vector<int> &arr, int n){
//     for(int i=n-2; i>=0; i--){
//         int maxi = 0;
//         for(int j=0; j<=i; j++){
//             if(arr[maxi+1]<arr[maxi]){
//                 int temp = arr[maxi];
//                 arr[maxi] = arr[maxi+1];
//                 arr[maxi+1] = temp;
//             }
//             maxi = maxi+1;
//         }
//     }
//     //printing
//     for(int i=0; i<n; i++){
//         cout<< arr[i] << " ";
//     }
//     cout<<endl;
// }
// int main(){
//     vector<int> arr = {10,9,3,7,1,5,2,6,4,8};
//     int size = arr.size();
//     bubble_sort(arr, size);
//     return 0;
// }

