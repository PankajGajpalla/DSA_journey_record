#include<iostream>
#include <climits>
using namespace std;



// int main()
// {
   
//     int arr[3][4];
//     // ways to write an is_array
    
//     // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
//     // int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};
//     // or write it like below row-wise or column-wise
//     // taking input row-wise for column wise just change to this - arr[j][i]
//     cout<<"enter : " <<endl;
//     for(int i=0; i<3; i++){
//         for(int j=0; j<4; j++){
//             cin >> arr[i][j]; 
//         }
//     }

//     for(int i=0; i<3; i++){
//         for(int j=0; j<4; j++){
//             cout << arr[i][j] << "  ";
//         }    
//         cout<<endl;
//     }



//     cout<< "maximum : "<<endl;
//     int maxi = 0;
//     for(int i=0; i<4; i++){
//         int sum =0;
//         for(int j=0; j<3; j++){
//             sum += arr[j][i];
//         }
//         if(maxi<sum){
//             maxi = sum;
//             // int col = 
//         }
//     }
//     cout<<maxi;
//     return 0;

// }

int print2largest(int arr[], int n) {
	    if(n<2) return -1;
	    
	    int largest = INT_MIN;
	    int Slargest = INT_MIN;
	    
	    for(int i=0; i<n; i++)
	    {
	        if(arr[i]>largest){
	            Slargest = largest;
	            largest = arr[i];
	        }
	        else if(arr[i]>Slargest && arr[i] != largest){
	            Slargest = arr[i];
	        }
	        
	    }
	    if(Slargest == INT_MIN){
	        return -1;
	    }
	    return Slargest;
};

//{ Driver Code Starts.

void zerolast(int arr[], int n){
    int j = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main() {
    int arr[] = {0,1,0,0,3,1,4,0,12};
    // cout<<print2largest(arr, 5);
    zerolast(arr, 9);
    for(int i=0; i<9;i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}