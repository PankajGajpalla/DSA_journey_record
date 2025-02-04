#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    
    //transfering all elements back to arr from temp;
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}
void merge_sort(vector<int> &arr, int low, int high){
    
    if(low >= high) return; //base case

    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);

    merge(arr, low, mid, high);

}
int main(){
    vector<int> arr = {9,1,5,7,0,2,4,3,6,8};
    int size = arr.size();

    merge_sort(arr, 0, size-1);

    //printing
    for(int i=0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
    return 0;
}