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
    void Helper(TreeNode*root , int mx , int mn){
        if(root==NULL){
            return;
        }
        //calc at each node
        if(root->val>mx)mx=root->val;
        if(root->val<mn)mn=root->val;
        int tmp=max(abs(mx-root->val),abs(mn-root->val));
        ans=max(ans,tmp);
        Helper(root->left,mx,mn);
        Helper(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        Helper(root,root->val,root->val);
        return ans;
    }
};