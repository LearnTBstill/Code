class Solution {
public:
    bool isValid(string s) {
        stack<char>kuohao;//用char类型而不能用string
        for(auto p=0;p<s.size();p++)
        {
            if(s[p]=='('||s[p]=='['||s[p]=='{') {kuohao.push(s[p]);continue;}//应当压入s[p]而非整个字符串s
            if(kuohao.empty()){return false;}//判空防止pop报错
            if(s[p]==')'&&kuohao.top()!='(') {return false;}
            if(s[p]=='}'&&kuohao.top()!='{') {return false;}
            if(s[p]==']'&&kuohao.top()!='[') {return false;}
            kuohao.pop();
        }
        return kuohao.empty();//要判断还有没有剩余的左括号
    }
};