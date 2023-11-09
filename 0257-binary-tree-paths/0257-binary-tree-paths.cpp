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
void Helper(TreeNode* root,string path,vector<string> &ans){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        path+=to_string(root->val);
        ans.push_back(path);
        return;
    }
    path+=to_string(root->val)+"->";
    Helper(root->left,path,ans);
    Helper(root->right,path,ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        //make string and add to vector when reached leaf node
        vector<string> ans;
        string path="";
        Helper(root,path,ans);
        return ans;
    }
};