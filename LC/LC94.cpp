#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans,left,right;
       if(root!=NULL){
           left=inorderTraversal(root->left);
           ans.insert(ans.end(),left.begin(),left.end());
           ans.push_back(root->val);
           right=inorderTraversal(root->right);
           ans.insert(ans.end(),right.begin(),right.end());
       }//返回值是数组，需要用insert将其与ans合并
        return ans;
    }