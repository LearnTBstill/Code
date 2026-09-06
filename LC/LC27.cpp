#include <vector>
using namespace std;
    int removeElement(vector<int>& nums, int val) {
        for(auto p=nums.begin();p<nums.end();)
        {
            if(*p==val) {p=nums.erase(p);}//注意p是指针，不能用来当作索引索引
            else {p++;}                 //一定要接受erase的值
        }
        return nums.size();
    }