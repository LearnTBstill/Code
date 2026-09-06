#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int slow = 1; // 第二个位置开始
        int n = nums.size();
        for (int fast=1;fast < n;fast++) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;//返回元素数
    }