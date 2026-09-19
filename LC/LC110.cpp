#include<string>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
 };
bool isBalanced(TreeNode* root) {
        if(root==NULL) {return true;}
        int sub=depth(root->left)-depth(root->right);
        if(sub>1||sub<-1){return false;}
        else{return isBalanced(root->left)&&isBalanced(root->right);}//别忘了所有子树也要平衡
    }
    int depth(TreeNode* p){
        if(p==NULL) {return 0;}
        return (max(depth(p->left),depth(p->right))+1);
    }