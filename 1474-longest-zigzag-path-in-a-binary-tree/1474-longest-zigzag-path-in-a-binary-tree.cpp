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
// Traverse in dfs fashion (with parameters current treenode, path and count) and keep track of previous path which took us here. While calling the current path (left or right) increment the count if the paths are different.
// Example:
// If the curr node is brought by path equal to left and we are going to move right, we increment count by 1
// If the curr node is brought by path equal to left and we are going to move left, we assign count as 1 because zigzag is interrupted by 2 lefts.

int maxc=0;
void Helper(TreeNode* root,string path,int c){
    if(root==NULL)return;
    maxc=max(maxc,c);
    if(path=="right" || path==""){
        Helper(root->left,"left",c+1);
    }
    else{
        Helper(root->left,"left",1);
    }

    if(path=="left" || path==""){
        Helper(root->right,"right",c+1);
    }
    else{
        Helper(root->right,"right",1);
    }
}
    int longestZigZag(TreeNode* root) {
        Helper(root,"",0);
        return maxc;
    }
};