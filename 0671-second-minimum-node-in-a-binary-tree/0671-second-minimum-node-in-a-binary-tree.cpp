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
long long mini=LONG_MAX;
long long ans=LONG_MAX;
void Helper(TreeNode* root){
    if(root==NULL){
        return;
    }
    if(root->val<mini){
        ans=mini;
        mini=root->val;
    }
    else if(root->val<ans && root->val!=mini){
        ans=root->val;
    }
    Helper(root->left);
    Helper(root->right);
}
    int findSecondMinimumValue(TreeNode* root) {
        Helper(root);
        if(ans==LONG_MAX){//no sec min
            return -1;
        }
        return ans;
    }
};