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
int sum=0;
    TreeNode* bstToGst(TreeNode* root) {
        //RNL is req
        if(root==NULL)return NULL;
        root->right=bstToGst(root->right);
        //calc
        root->val=sum+root->val;
        sum=root->val;
        root->left=bstToGst(root->left);
        return root;
    }
};