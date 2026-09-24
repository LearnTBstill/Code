#include<vector>
using namespace std;
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode* root){
	vector<int>pre;
	preorder(pre,root);
	return pre;
}

void preorder(vector<int>& pre,TreeNode* root){
	if(root!=NULL){
		pre.push_back(root->val);
		preorder(pre,root->left);//不用再传地址
		preorder(pre,root->right);
	}
}