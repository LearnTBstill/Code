#include<string>
using namespace std;
bool isPalindrome(string s) {
        int p=0,q=s.size()-1;
        while(p<q){
            if(!((s[p]>='A'&&s[p]<='Z')||(s[p]>='a'&&s[p]<='z')||(s[p]>='0'&&s[p]<='9'))){//直接用字符比较就可以，不用ASCII
                p++;
                continue;
            }
            else if(s[p]>='A'&&s[p]<='Z'){
                s[p]+=32;
                continue;
            }
            if(!((s[q]>='A'&&s[q]<='Z')||(s[q]>='a'&&s[q]<='z')||(s[q]>='0'&&s[q]<='9'))){
                q--;
                continue;
            }
            else if(s[q]>='A'&&s[q]<='Z'){
                s[q]+=32;
                continue;
            }
            if(s[p]==s[q]){p++;q--;}
            else{return false;}
        }
        return true;
    }