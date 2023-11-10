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
    vector<vector<string>>ans;
    int  Height(TreeNode* root){
        if(root==NULL)return 0;
        int lh=Height(root->left);
        int rh=Height(root->right);
        return max(lh,rh)+1;
    }
    void Helper(TreeNode* root,int h,int r,int c){
        if(root==NULL)return;
        ans[r][c]=to_string(root->val);
        int temp=pow(2,h-r-2);//dry run by example
        Helper(root->left,h,r+1,c-temp);
        Helper(root->right,h,r+1,c+temp);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int r=Height(root);
        int c=pow(2,r)-1;
        ans.resize(r,vector<string>(c,""));
        Helper(root,r,0,c/2);
        return ans;
    }
};