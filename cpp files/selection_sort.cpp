#include<iostream>
#include<vector>
using namespace std;

void selection_sort(int size, vector<int> &arr){
    for(int i=0; i<size-1; i++){
        int mini = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
    //printing...
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {5,2,3,1,4};
    int size = arr.size();
    cout<<"before selection sort: "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"after selection sort: "<<endl;
    selection_sort(size,arr);
    return 0;

}