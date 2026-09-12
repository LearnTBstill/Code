#include <string>
using namespace std;
string addBinary(string a, string b) {//string不以\0结尾
        int in=0;string end;int i=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(i<a.size()&&i<b.size())
        {
            end.push_back((a[i]-'0'+b[i]-'0'+in)%2+'0');//end是空字符串，必须用push_back     数字字符减去'0'等于对应整数
            in=(a[i]-'0'+b[i]-'0'+in)/2;
            i++;
        }
        while(i<a.size())
        {
            end.push_back((in+a[i]-'0')%2+'0');
            in=(in+a[i]-'0')/2;
            i++;
        }
        while(i<b.size())
        {
            end.push_back((in+b[i]-'0')%2+'0');
            in=(in+b[i]-'0')/2;
            i++;
        }
        if(in==1)
        {
            end+="1";
        }
        reverse(end.begin(),end.end());
        return end;
    }