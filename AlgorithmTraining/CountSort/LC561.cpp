#include<vector>;
using namespace std;
int arrayPairSum(vector<int>& nums) {//min max只能两个值之间，而min_element可以是迭代器，切记返回值是指针 
        int minval=*min_element(nums.begin(),nums.end());
        int maxval=*max_element(nums.begin(),nums.end());
        int k=maxval-minval;
        vector<int> temp(k+1,0);//计数数组大小是k+1
        for(int i=0;i<nums.size();i++){
            temp[nums[i]-minval]++;
        }
        int answer=0;
        int judge=0;//判断奇偶
        for(int i=0;i<temp.size();i++){
            while(temp[i]>0){
                if(judge%2==0){
                    answer+=i+minval;
                }
                judge++;
                temp[i]--;
            }
        }
        return answer;
    }