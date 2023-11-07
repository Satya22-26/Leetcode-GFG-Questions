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
int ans=INT_MIN;
int Helper(TreeNode* root){
    //simple post order
    if(root==NULL)return 0;
    int left=Helper(root->left);
    int right=Helper(root->right);

    left=max(0,left);
    right=max(0,right);
    
    int pathsum=left+right+root->val;//at node we sum from both left and right but we send parent the max
    ans=max(ans,pathsum);
    return max(left,right)+root->val;
}
    int maxPathSum(TreeNode* root) {
        Helper(root);
        return ans;
    }
};