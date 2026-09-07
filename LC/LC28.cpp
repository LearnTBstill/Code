#include<string>
using namespace std;
int strStr(string haystack, string needle) {
        int s=0,j=0;
        for(int i=0;i<haystack.size()+1;)
        {
            if(needle[s]=='\0') {return j;}
            if(haystack[i]!=needle[s])
            {
                j++;
                i=j;
                s=0;
            }
            else
            {
                s++;i++;
            }
        }
        return -1;
    }