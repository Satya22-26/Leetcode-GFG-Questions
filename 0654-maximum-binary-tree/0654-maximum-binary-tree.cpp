/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode*  Helper(vector<int>& nums,int s,int e){
    if(s>e)return NULL;
    int  maxi=s;
    for(int i=s+1;i<=e;i++){
        if(nums[i]>nums[maxi])maxi=i;
    }
    TreeNode* root=new TreeNode(nums[maxi]);
    root->left=Helper(nums,s,maxi-1);
    root->right=Helper(nums,maxi+1,e);
    return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);
    }
};