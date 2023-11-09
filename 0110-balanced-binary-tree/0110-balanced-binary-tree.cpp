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
int HeightofTree(TreeNode* root){
    if(root==NULL)return 0;
    int lh=HeightofTree(root->left);
    int rh=HeightofTree(root->right);
    //left  or right subtree  is unbalanced
    if(lh==-1 || rh==-1 || abs(lh-rh)>1)return -1;
    return max(lh,rh)+1;
}
    bool isBalanced(TreeNode* root) {
        //just use postorder  to height and add condition in node calc
        if(root==NULL)return true;
        if(HeightofTree(root)==-1)return false;
        return true;
    }
};