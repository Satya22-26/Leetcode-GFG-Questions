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
map<string,int> mp;
vector<TreeNode*> ans;
string solve(TreeNode* root)
      {
          if(root==NULL) return "#";
          string s=solve(root->left)+","+solve(root->right)+","+to_string(root->val);
          
    
          if(mp[s]==1)
          {
              ans.push_back(root);
          }
          mp[s]++;
          return s;
      }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        //PREFER POSTORDER TRAVERSAL,WHILE RETURNING FROM DFS TRAVERSAL STORE THE SUBTREE IN MAP AND CHECK IF ITS ALREADY EXIST OR NOT
        solve(root);
        return ans;
    }
};