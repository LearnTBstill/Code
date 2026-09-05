#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;)
        {
            if(nums[i]==nums[i+1]) {nums.erase(nums.begin()+i);}//eraze要用迭代器
            else {i++;}
        }
        return nums.size();
    }