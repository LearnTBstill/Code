#include<vector>
#include<algorithm>
using namespace std;
int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        sort(nums.begin(),nums.end());
        return nums[n];
    }