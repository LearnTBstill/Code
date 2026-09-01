#include<string>
using namespace std;
int romanToInt(string s) {
        int num=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='I')
            {
                if(s[i+1]=='V') {num+=4; i++; continue;}
                if(s[i+1]=='X') {num+=9; i++; continue;}
                num+=1; continue;
            }
            if(s[i]=='X')
            {
                if(s[i+1]=='L') {num+=40; i++; continue; }
                if(s[i+1]=='C') {num+=90; i++; continue; }
                num+=10; continue;
            }
            if(s[i]=='C')
            {
                if(s[i+1]=='D') {num+=400; i++; continue;}
                if(s[i+1]=='M') {num+=900; i++; continue; }
                num+=100; continue;
            }
            if(s[i]=='V')  {num+=5; continue;}
            if(s[i]=='L')  {num+=50; continue;}
            if(s[i]=='D')  {num+=500; continue;}
            if(s[i]=='M')  {num+=1000; continue;}
        }
        return num;
    }
    //也可以用map做，这样就不显得那么冗余了