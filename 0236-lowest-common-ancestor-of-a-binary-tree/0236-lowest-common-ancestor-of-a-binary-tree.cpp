/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //search for p and q in both subtrees if found both ,then the current root will be LCA
        //if one found and another not , one found is ans
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q)return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL){
            return  root;
        }
        if(left==NULL){
            return right;
        }
        else{
            return left;
        }

    }
};