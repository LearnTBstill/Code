#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        insertsort(nums1);
        insertsort(nums2);
        int i=0,j=0;
        vector<int> arr;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]==nums2[j]){
                if(arr.empty()||arr.back()!=nums1[i]){
                    arr.push_back(nums1[i]);
                }
                i++;j++;
            }
            else{
                nums1[i]>nums2[j]?j++:i++;
            }
        }
        return arr;
    }

    void insertsort(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            int temp=nums[i];
            int j=i-1;
            for(j;j>=0;j--){//不要忘了j>=0
                if(temp<nums[j]){
                    nums[j+1]=nums[j];
                }
                else{
                    break;
                }
            }
            nums[j+1]=temp;
        }
    }
};