#include <vector> 
using namespace std;
int removeElement(vector<int>& nums, int val) {
        int low=0,high=0;
        int n=nums.size();
        while(high<n)
        {
            if(nums[high]!=val)
            {
                nums[low]=nums[high];
                low++;
            }
            high++;
        }
        return  low;
    }