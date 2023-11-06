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
int dia=INT_MIN;
//we will just calculate diameter in eacg height calc process
    int heightofTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=heightofTree(root->left);
        int rh=heightofTree(root->right);
        dia=max(dia,lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //recursion o(n)
        heightofTree(root);
        return dia;

    }
};