#include<vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
        for(int l=digits.size()-1;l>=0;l--)//如果把l用auto声明，会变成无符号整数，死循环了
    {
        if(digits[l]!=9){
            digits[l]++;
            return digits;
        }
        digits[l]=0;
    }
    digits.insert(digits.begin(),1);
    return digits;
    }