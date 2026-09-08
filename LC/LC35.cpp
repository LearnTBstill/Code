#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        auto p=0;
        for(p;p<nums.size();p++){
           if(nums[p]==target){
               return p; 
            }
            else if(nums[p]<=target){continue;}
            else{nums.insert(nums.begin()+p,target);return p;}
        }
        nums.push_back(target);
        return p;
    }