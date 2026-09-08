#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int mid=0;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target) {return mid;}
            if(nums[mid]<target) {low=mid+1;}
            if(nums[mid]>target) {high=mid-1;}
        }
        return low;
    }