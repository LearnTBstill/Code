#include<vector>
#include<string>
using namespace std;
int strStr(string haystack, string needle) {
        vector<int> next(needle.size()+1);
        getnext(next,needle);
        int i=1,j=1;//下标从1开始，且后面访问字符串要减去1 （因为传入的字符串下标从0开始）
        while(i<=haystack.size()&&j<=needle.size()){
            if(j==0||haystack[i-1]==needle[j-1]){
                i++;j++;
            }
            else{
                j=next[j];
            }
        }
        if(j<=needle.size()){
            return -1;
        }
        else{
            return i-needle.size()-1;//返回值下标-1 
        }
    }

    void getnext(vector<int>& next,string str){
        int i=1,j=0;
        next[1]=0;
        while(i<str.size()){
            if(j==0||str[i-1]==str[j-1]){//传入的字符串从零开始，所以访问时下标减去1 
                i++;j++;
                next[i]=j;
            }
            else{
                j=next[j];
            }
        }
    }