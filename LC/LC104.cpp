#include<string>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};
int maxDepth(TreeNode* root) {
    if(root==NULL) {return 0;}
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}