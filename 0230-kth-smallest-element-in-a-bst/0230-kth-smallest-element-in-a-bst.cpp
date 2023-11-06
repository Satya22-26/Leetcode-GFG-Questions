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
int c=0;
int ans;
void Helper(TreeNode* root, int k){
    if(root==NULL)return;
    //lnr
    Helper(root->left,k);
    c++;
    if(c==k){
        ans=root->val;
        return;
    }
    Helper(root->right,k);

}
    int kthSmallest(TreeNode* root, int k) {
        //lower values bst --inorder
        //inorder of BST is sorted
        //look at diagrm--lowest will be always among the leftmost elements
        //no space we want
       // int  ans=0;
        Helper(root,k);
        return ans;
    }
};