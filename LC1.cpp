#include<vector>
using namespace std;
vector<int> twoSum(vector<int>&arr,int target)//用&传节省开销
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]+arr[j]==target)
            return {i,j};
        }
    }
    return {};
}