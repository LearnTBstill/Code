#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode* sortedArrayToBST(vector<int>& nums) {
        return a(nums,0,nums.size()-1);
    }
TreeNode* a(vector<int>&nums,int left,int right){//传地址减少开销
    TreeNode* root=new TreeNode;//提前创建新的结点，只声明的话root->val报错
    int mid=0;
	if(left>right) {return NULL;}
	mid=(left+right)/2;
	root->val=nums[mid];
	root->left=a(nums,left,mid-1);
	root->right=a(nums,mid+1,right);
	return root;
}