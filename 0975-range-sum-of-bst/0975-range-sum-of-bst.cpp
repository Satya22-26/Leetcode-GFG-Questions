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
    void Helper(TreeNode* root, int l, int h){
        if(root==NULL)return;
        if(root->val<=h && root->val>=l){
            sum+=root->val;
        }
        Helper(root->left,l,h);
        Helper(root->right,l,h);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        //normal dfs  and if in range add
        Helper(root,low,high);
        return sum;
    }
};