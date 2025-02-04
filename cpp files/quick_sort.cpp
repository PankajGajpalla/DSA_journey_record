#include<iostream>
#include<vector>
using namespace std;

int partion_index(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i] <= pivot && i<=high-1){
            i++;
        }
        while(arr[j] >= pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if(low < high){
        int P_index = partion_index(arr, low, high);
        quick_sort(arr, low, P_index -1);
        quick_sort(arr, P_index +1, high);
    }

}

int main()
{
    vector<int> arr = {9,10,5,8,1,4,2,3,6,0,7};
    int size = arr.size();

    quick_sort(arr, 0, size-1);

    for(int i=0; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;

    return 0;

}