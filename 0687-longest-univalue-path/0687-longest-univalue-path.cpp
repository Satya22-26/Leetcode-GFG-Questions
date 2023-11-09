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
int Helper(TreeNode* root,int &ans){
    if(root==NULL)return 0;
    int lh=Helper(root->left,ans);
    int rh=Helper(root->right,ans);
    if(!root->left || root->left->val!=root->val)lh=0;
    if(!root->right || root->right->val!=root->val)rh=0;
    ans=max(ans,lh+rh);
    return 1+max(lh,rh);
}
    int longestUnivaluePath(TreeNode* root) {
        //here not number of nodes rather path
        //use postorder height just little modification
        int ans=0;
        Helper(root,ans);
        return ans;
    }
};