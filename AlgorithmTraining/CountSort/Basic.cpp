#include<vector>
using namespace std;
void count(vector<int>& arr,int k,vector<int>& answer){//k为待排数组的取值范围
    vector<int> A(k,0);
    for(int i=0;i<arr.size();i++){
        A[arr[i]]++;
    }
    for(int i=1;i<k;i++){//确定数字的最终位置
        A[i]+=A[i-1];
    }
    for(int i=arr.size()-1;i>=0;i--){
        answer[--A[arr[i]]]=arr[i];
    }
}