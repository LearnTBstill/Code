#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
        string str="";
        for(auto j=0;j<strs[0].size();j++)
        {
            auto c=strs[0][j];
            for(auto i=0;i<strs.size();i++){
                if(j>=strs[i].size()||strs[i][j]!=c)  return str;//vector不能用length查大小                                                                
            }                                                    //只能用size
            str+=c;
        }
        return str;
    }