#include<vector>
using namespace std;
int heightChecker(vector<int>& heights) {//交换次数不等于答案
        int num=0;
        vector<int>expected=heights;
        for(int i=0;i<expected.size();i++){
            bool change=false;
            for(int j=expected.size()-1;j>i;j--){
                if(expected[j]<expected[j-1]){
                    num=expected[j];
                    expected[j]=expected[j-1];
                    expected[j-1]=num;
                    change=true;
                }
            }
            if(change==false){
                break;
            }
        }
        num=0;
        for(int i=0;i<expected.size();i++){
            if(expected[i]!=heights[i]){
                num++;
            }
        }
        return num;
    }