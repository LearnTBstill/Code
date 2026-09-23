#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
         int i=0;
        for(int j=0;j<nums.size();j++){
            i^=nums[j];
        }
        return i;
    }