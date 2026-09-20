#include<string>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int minDepth(TreeNode* root){//是到最近的叶node而不是null
        if(root==NULL){return 0;}
        else if(root->left==NULL){
            return minDepth(root->right)+1;//要考虑单侧子树的情况
        }
        else if(root->right==NULL){
            return minDepth(root->left)+1;
        }
        return min(minDepth(root->left),minDepth(root->right))+1;
    }