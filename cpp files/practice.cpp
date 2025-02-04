#include<iostream>
#include<vector>
using namespace std;

void sorto(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        int j = i;
        while(j>0 && nums[j-1]>nums[j])
        {
            swap(nums[j-1], nums[j]);
            j--;
        }
    }
}
int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sorto(nums);
    for(int i=0; i<nums.size(); i++){
        cout<< nums[i] << " ";
    }
    // return 0;
}