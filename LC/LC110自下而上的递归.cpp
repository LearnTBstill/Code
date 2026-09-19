#include<string>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
 };
bool isBalanced(TreeNode* root) {
        return depth(root)!=-1;
    }
    int depth(TreeNode* p){
        if(p==NULL) {return 0;}
        int lh=depth(p->left),rh=depth(p->right);
        int sub=lh-rh;
        if(sub>1||sub<-1||lh==-1||rh==-1){return -1;}
        return (max(lh,rh)+1);
    }