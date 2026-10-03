#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
        int min=0,mid=0;
        for(int i=0;i<nums.size();i++){
            min=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[min]){min=j;}
            }
            if(min!=i){
                mid=nums[min];
                nums[min]=nums[i];
                nums[i]=mid;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return nums.size();
    }